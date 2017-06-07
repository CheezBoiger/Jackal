"""
  Copyright (c) Jackal Engine, MIT License.
"""
import os
import sys

def CheckOS(cmake_config):
  platform = sys.platform
  if platform.startswith('win32'):
    cmake_config = cmake_config + " "
    
  return cmake_config


def main():
  path = os.path.dirname(os.path.realpath(__file__))
  os.chdir(path)
  os.system("git submodule update --init")
  if not os.path.isdir("Build"):
    os.mkdir("Build")
    
  os.chdir("Build")
  configs = ""
  configs = CheckOS(configs)
  
  os.system("cmake" + configs + " ../Jackal")

if __name__ == "__main__":
  main()