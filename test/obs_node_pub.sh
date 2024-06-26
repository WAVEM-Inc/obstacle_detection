#!bin/bash
ros2 topic pub /drive/info route_msgs/msg/DriveState "code: 'arrive'
speaker: 0
start_node:
  node_id: '201'
  position:
    latitude: 36.11361380000634
    longitude: 128.368702800012
  type: 'work_node'
  kind: 'endpoint'
  heading: 148.0
  direction: ''
  driving_option: ''
  detection_range: []
end_node:
  node_id: '202'
  position:
    latitude: 36.113596
    longitude: 128.368733
  type: ''
  kind: 'waiting'
  heading: 148.0
  direction: ''
  driving_option: ''
  detection_range: [{offset: 1.0, width_left: 0.5, width_right: 0.5, height: 5.0, action_code: waiting}]" 

