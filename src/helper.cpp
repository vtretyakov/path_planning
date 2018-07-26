//
//  helper.cpp
//  path_planning
//
//  Created by Viatcheslav Tretyakov on 26.07.18.
//

#include "helper.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

Helper::Helper() {
    
}

Helper::~Helper() {
    
}

vector<double> Helper::get_closest_car_dist_in_lanes(const vector<vector<double>> &fusion_data, double car_s, double car_d, int prev_path_size) {
    cout << "car_s: " << car_s << " car_d: " << car_d << endl;
 // vector<double> car_dist;
 // vector<double> car_dist_per_lane(3);
  vector<double> smallest_car_dist_per_lane = {10000.0,10000.0,10000.0};
  
  for (int i = 0; i < fusion_data.size(); i++) {
    float d = fusion_data[i][6];
    for (int lane = 0; lane < 3; lane++) {//we have 3 lanes
      if (d < (2+4*lane+2) && d > (2+4*lane-2)) {
        double s = fusion_data[i][5];
        double vx = fusion_data[i][3];
        double vy = fusion_data[i][4];
        double speed = sqrt(vx*vx + vy*vy);
        s += ((double)prev_path_size*.02*speed);
        if (s < smallest_car_dist_per_lane[lane]) {
         // car_dist_per_lane[lane] = s;
            double dist = s - car_s;
            if (dist > 0){
              smallest_car_dist_per_lane[lane] = dist;
            }
        }
      }
    }
    
  }
    
  return smallest_car_dist_per_lane;
}

vector<double> Helper::get_closest_cer_vel_in_lanes() {
  vector<double> car_vel;
    
  return car_vel;
}

bool Helper::increasing_order(int i, int j) {
  return (i<j);
}
