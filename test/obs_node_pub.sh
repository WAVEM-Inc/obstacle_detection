#!bin/bash
ros2 topic pub /drive/info route_msgs/msg/DriveState "code: 'arrive'
speaker: 0
start_node:
  node_id: '201'
  position:
    latitude: 37.30601717834749
    longitude: 127.2401849537135
  type: ''
  kind: 'connecting'
  heading: 148.0
  direction: ''
  driving_option: ''
  detection_range: []
end_node:
  node_id: '202'
  position:
    latitude: 37.3060259
    longitude: 127.240167
  type: ''
  kind: 'waiting'
  heading: 148.0
  direction: ''
  driving_option: ''
  detection_range: [{offset: 2.0, width_left: 2.0, width_right: 2.0, height: 4.0, action_code: driving}]" 

