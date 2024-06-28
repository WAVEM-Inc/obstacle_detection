#!bin/bash
ros2 topic pub /drive/info route_msgs/msg/DriveState "code: 'arrive'
speaker: 0
start_node:
  node_id: '201'
  position:
    latitude: 37.34234235
    longitude: 138.435345
  type: 'work_node'
  kind: 'endpoint'
  heading: 148.0
  direction: 'forward'
  driving_option: ''
  detection_range: []
end_node:
  node_id: '202'
  position:
    latitude: $2
    longitude: $3
  type: ''
  kind: 'waiting'
  heading: $1
  direction: 'forward'
  driving_option: ''
  detection_range: [{offset: $4, width_left: $6, width_right: $7 , height: $5, action_code: waiting}]" 

