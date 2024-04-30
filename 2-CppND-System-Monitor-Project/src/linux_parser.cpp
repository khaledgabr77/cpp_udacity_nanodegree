#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>
#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  std::string memTotal, memFree, value;
  std::string line;
  std::string key;
  std::ifstream file(kProcDirectory + kMeminfoFilename);
  if (file.is_open()) {
      while (std::getline(file, line)) {
          std::replace(line.begin(), line.end(), ':', ' ');
          std::istringstream linestream(line);
          linestream >> key >> value;
          if (key == "MemTotal") {
              //std::cout << "MemTotal: " << value << std::endl; // Debug print
              memTotal = value;
          } else if (key == "MemFree") {
              //std::cout << "MemFree: " << value << std::endl; // Debug print
              memFree = value;
              break; // No need to continue reading the file
          }
      }
  }
  //std::cout << "memTotal: " << memTotal << ", memFree: " << memFree << std::endl; // Debug print
  return (std::stof(memTotal) - std::stof(memFree)) / std::stof(memTotal);
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  
  std::string upTime, line, key, value;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if(stream.is_open()){
    std::getline(stream, line);
    std::istringstream streamline(line);
    streamline >> upTime;
    // std::cout << upTime << std::endl; // Debug print
    
  }
  return stol(upTime); }

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { 
  vector<string> jiffValues = LinuxParser::CpuUtilization();
  vector<long> kk(10,0);
  long total = 0;
  vector<CPUStates> names= {kUser_, kNice_, kSystem_, kIdle_, kIOwait_, kIRQ_, kSoftIRQ_, kSteal_};
  for (auto i : names){
    kk[i] = std::stol(jiffValues[i]);
    total += kk[i];
  }
  
  return total; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) { 
  string utime, stime, line;
  std::vector<string> actJiff;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if(stream.is_open()){
    while (std::getline(stream, line))
    {
        std::istringstream linestream(line);
        while(linestream >> line)
        actJiff.push_back(line);
    }
    
  }

  return stol(actJiff[13] + actJiff[14]); }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 
  
  vector<string> actJiff = LinuxParser::CpuUtilization();
  vector<long> lol(actJiff.size(), 0); // Initialize vector with size of actJiff
    
  vector<CPUStates> names= {kUser_, kNice_, kSystem_, kIdle_, kIOwait_, kIRQ_, kSoftIRQ_, kSteal_};
  
  for(auto i : names){
    lol[i] = stol(actJiff[i]);
  }
  
  return (lol[0] + lol[1] + lol[2] + lol[3] + lol[4] + lol[5] + lol[6] + lol[7]);
}
// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { 
  vector<string> actJiff = LinuxParser::CpuUtilization();

  return stol(actJiff[CPUStates::kIdle_]) + stol(actJiff[CPUStates::kIOwait_]); }

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {
  string line, value, key;
  vector<string> values;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> key;
    while (linestream >> value) {
      values.push_back(value);
    }
  }
  return values;
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
  
  string line, key, value;
  string totProc;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if(stream.is_open()) {
    while(std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if(key == "processes") {
          totProc = value;
        }
      }
    }
  
  return std::stoi(totProc);
   }

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  string key, value, runProc, line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if(stream.is_open()){
    while(std::getline(stream, line)){
      std::istringstream linestream(line);
      linestream >> key >> value;
      if(key == "procs_running"){
        runProc = value;
      }

    }
  }
  return std::stoi(runProc); }

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
  
  string line;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kCmdlineFilename);

  if(stream.is_open()){
    std::getline(stream, line);
  }
  return line; }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
std::string LinuxParser::Ram(int pid) { 
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  std::string line, key, value;
  std::string ram = "0"; // Default value

  if(stream.is_open()) {
      while (std::getline(stream, line)) {
          std::istringstream linestream(line);
          linestream >> key >> value;
          if(key == "VmSize:") {
              ram = value;
              break;
          }
      }
  }

  return to_string(stol(ram)/ 1024);
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) { 
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  std::string line, key, value;
  std::string udi = "0"; // Default value

  if(stream.is_open()) {
      while (std::getline(stream, line)) {
          std::istringstream linestream(line);
          linestream >> key >> value;
          if(key == "Uid:") {
              udi = value;
              break;
          }
      }
  }

  return udi;
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 
  
  string userr = LinuxParser::Uid(pid);
  std::ifstream stream(kPasswordPath);
  std::string line, name, udi, x;
  std::string uu = "0"; // Default value
  if(stream.is_open()){
    while(std::getline(stream, line)){
      std::replace(line.begin(), line.end(), ':',' ');
      std::istringstream linestream(line);
      while(linestream >> name >> x >> udi) {
        if(udi == userr){
          uu = name ;
      }
      }

    }
  }
  return uu; }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
  string line, value;
  vector<string> values;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (linestream >> value) {
      values.push_back(value);
    };
  }
  return LinuxParser::UpTime() - (stol(values[21]) / 100);
}