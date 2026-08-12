## Push_swap

### Setting up a visualizer

Build a [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) to monitor program activity, changing a few things to make sure it works on more modern versions of Ubuntu (disabling one warning and correcting the `cmake` call path):
```
git clone https://github.com/o-reo/push_swap_visualizer
cd push_swap_visualizer
sed -i 's/-Werror>$/-Werror -Wno-ignored-attributes>/' src/CMakeLists.txt
export PATH=/usr/bin:/home/<YOUR_USERNAME>/.local/bin:$PATH
mkdir build
cd build
cmake ..
make
```
The resulting **push_swap_visualizer/build/bin** directory contains the visualizer files. Copy the folder to where the compiled **push_swap** program resides, and run it via `./visualizer`. There will be three settings tables: *Controls*, *Values*, and *Commands*. They might be overlapping, so just move the top one around to see if there's another underneath, then use the *Scale UI* bar to resize them. These table positions (but not resizing settings) will be saved in the **imgui.ini** file for next use.

In the *Values* container, enter a number into the *Count* input and click *Shuffle*, or enter your own list into the *Values* input. Ensure the the correct `../push_swap` file path is entered and select *Compute*. Now, in the *Controls* box, click *Start* to commence the visualization, and control *Speed* and playback actions as needed while it runs.
