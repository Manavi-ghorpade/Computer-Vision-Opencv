# Computer-Vision-Opencv

e have used the Dark Room Laser Spot video we converted to a 
series of graymap frames (using ONE band from RGB). we have applied the 
threshold function on each frame which differentiate the pixels we are interested in 
from the rest. if the intensity of the pixel img(x,y) is higher than threshold, then the 
new pixel intensity is set to a maxval. Otherwise, the pixels are set to 0.we have 
used the threshold value of 127 and maxval=255 if we find any pixel with 127 
intensity or more then we will assign that pixel the new intensity 255.Then we 
have traveled through the each pixel of the frame and checked the intensity of pixel 
(by using ‘image.at(y,x)[channel]’) for 255 and once found the pixel of intensity 
255 then we added that pixel’s x and y coordinates to the vector of vector. After 
doing that we calculated x left by iterating through the vector of vector and 
founded the minimum value of x and assigned it to xleft, similarly we founded 
ytop with minimum value of y from vector of vector, we got x right by calculating 
the max value of x in vector of vector and ybottom from calculating the max value 
of y in the vector of vector.

Then we calculated the x bar and y bar by the formula then applied the centroid formula to get centroid of 
laser spot and then drew the cross-hair of saturation 255 on that centroid by using 
drawMarker method. we have calculated centroid for each frame and draw cross 
hair and then saved frame using imwrite in pgm format. To store image using 
imwrite in pgm format first we applied the split function and then we have passed 
the single channel image to imwrite so it will store the image in the pgm format. 

We have used the following ffmpeg command to get the mpeg4 format video.

ffmpeg -framerate 30 -i %d.pgm -r 30 -c:v mpeg4 ques6.mp4

We have another method where we have used the videowriter to write the video 
instead of saving the frames in folder. This method is straightforward, we did the 
same operations as above on the frame. But we did not write all the frames into a 
pgm file, instead we used the video writer object to store all the frames. And at the 
end we got the output video as an output stored at specified location.

Run code:

           make

          ./< name >
