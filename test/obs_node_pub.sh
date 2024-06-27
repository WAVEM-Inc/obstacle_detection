#!bin/bash
ros2 topic pub /drive/info route_msgs/msg/DriveState "code: 'arrive'
speaker: 0
start_node:
  node_id: '201'
  position:
    latitude: 36.1144324
    longitude: 128.3691
  type: 'work_node'
  kind: 'endpoint'
  heading: 148.0
  direction: 'forward'
  driving_option: ''
  detection_range: []
end_node:
  node_id: '202'
  position:
    latitude: 36.1145078
    longitude: 128.3691
  type: ''
  kind: 'waiting'
  heading: 148.0
  direction: ''
  driving_option: ''
  detection_range: [{offset: 1.0, width_left: 3.0, width_right: 1.0, height: 20.0, action_code: waiting}]" 

