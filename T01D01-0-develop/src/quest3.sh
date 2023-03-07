#!/bin/bash

cd ./door_management_file/
mkdir door_map
mkdir door_logs
mkdir door_configuration

mv *.log door_logs
mv door_map_1.1 door_map
mv *.conf door_configuration
