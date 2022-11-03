# Thermostate
Simple thermostate simulation. The application simulates the behaviour of a thermostate. It offers the user the possibility to custom the minimum and maximum temperature that he would like to have in a room. If the temperature is not in the define interval, the cooling or heating functions will be trigered so the temperature in the room will get in the needed interval.

<h2>Installation<h2>
  Run the following commands to clone the repo and build it
  
1. Clone the repo
   
  ```sh
   git clone https://github.com/xgrozasergiu/thermostate.git
   ```
  
2. Create build folder
  
  ```sh
  cd thermostate
  mkdir build
  cd build
  ```
  
3. Build using Cmake
  
  ```sh
   cmake ..
   make
   ```
  
<h2>Usage<h2>
Run the executable:
    
 ```sh
  ./thermostate 
  ```

  
<h2>Class diagram<h2>
  <img src="pic/thermostate.drawio.png" alt="Logo" width="480" height="380">
