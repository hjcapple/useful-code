#!/usr/bin/python
# -*- coding: UTF-8 -*- 

import sys
import os

def usage():
    name = os.path.split(sys.argv[0])[1]
    print("usage: {} filePath".format(name))

def byte_to_hexstr(byte):
    return "0x" + byte.encode('hex')

def write_hex_rawdata(file, data):
    file.write("    ")
    count = 0
    for i in range(0, len(data)):
        file.write(byte_to_hexstr(data[i]))
        if i + 1 != len(data):
            file.write(", ")

        count = count + 1
        if count == 16:
            count = 0
            file.write("\n    ")

#################################
if __name__ == '__main__':
    if len(sys.argv) != 2:
        usage()
        exit(1)

    file_path = sys.argv[1]
    with open(file_path, "rb") as f:
        file_data = f.read()

    script_name = os.path.split(sys.argv[0])[1]
    file_name = os.path.split(sys.argv[1])[1]

    souce_path = file_path + ".h"
    with open(souce_path, 'w') as f:
        f.write("// This file is generated by {} and {}, DO NOT EDIT!".format(script_name, file_name))
        f.write("\n")
        f.write("static const uint8_t s_{}_data[{}] = ".format(file_name.replace(".", "_"), len(file_data)))
        f.write("{\n")
        write_hex_rawdata(f, file_data)
        f.write("\n};")
        f.write("\n")


