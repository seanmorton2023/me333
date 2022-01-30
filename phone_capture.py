import cv2
import numpy as np
import requests #for IP webcam
import imutils
import time

#for resizing/rescaling image; less resolution -> faster img processing
from skimage.transform import rescale, resize, downscale_local_mean

#some of the IP addresses of my phone cameras at diff places
ipv4_url = 'http://10.0.0.164:8080/shot.jpg' #sherman apt
#ipv4_url = 'http://10.105.76.135:8080/shot.jpg' #northwestern
#ipv4_url = 'http://10.105.178.194:8080/shot.jpg' #northwestern 2
#ipv4_url = None

'''########################

NOTE!

This is an adaptation of my object detector code I was using 
for my MDS research project. Please look under ME395
or MDS Research Summer directories for the real thing--
all I wanted here was the IP-connected image capture.

#############################
'''

#create a new class for object detector: makes member
#data and functions
class ObjectDetector:

    def __init__(self, thres_input, nms_input):
        pass

    def config_video(self):
        '''sets up video self.captures for object detection
        grab an image, define parameters on the size and brightness of 
        the image. also sets default parameters for the net; required 
        to run. if you design your own model, that's when you need 
        to dork with the dnn values

        "coco" gives the class names. better to import them all from a
        file than write all 90 class names individually
        '''

        self.cap = cv2.VideoCapture(1)
        self.cap2 = cv2.VideoCapture(2)

        #size
        self.cap.set(3, 640)
        self.cap.set(4, 480)

        #brightness
        self.cap.set(10,150)
       

    def gather_camdata(self, ip_url = None):
        '''get data from either laptop webcams or from phone camera
        gather data from both cameras

        if user gives an IP address, use phone cam as primary cam. else,
        use laptop webcam as primary cam
        '''

        if ip_url:

            #handle the various errors that can happen when you try
            #to get phone input: ConnectionError, InvalidURL, and more
            img_response = requests.get(ip_url)

            img_array = np.array(bytearray(img_response.content), dtype = np.uint8)

            #decode, resize and show the image data
            image = cv2.imdecode(img_array, -1)

            #testing out resizing of the image to reduce image filedata; optimize for speed
            scale_percent = 60 #for ME333 stuff
            #scale_percent = 20 #best performance with an acceptable resolution\
            width = int(image.shape[1] * scale_percent/100)
            height = int(image.shape[0] * scale_percent/100)
            dim = (width, height)

            image = cv2.resize(image, dim, interpolation = cv2.INTER_AREA)

            #image = imutils.resize(image, width=1000, height=1000)
            image = imutils.resize(image, width=500, height=500) #smaller window


        else:
            _, image = self.cap.read()

        #second capture, from webcam #2. may or not be active; handled later
        _, image2 = self.cap2.read()

        return image, image2

    def display(self, image, image2):
        '''display images to screen.
        camera 2 may not always be connected; error is handled here
        '''

        cv2.imshow("Camera 1", image)
        try:
            cv2.imshow("Camera 2", image2)
        except cv2.error:
            #print("CV error: data not read from camera 2")
            pass

#make a main function so that we can determine whether or not to run the code
#in this file. especially useful for the streamlit app, which imports
#the object detector class but doesn't run the exact same code

if __name__ == '__main__':

    od = ObjectDetector(0.45, 0.5)
    od.config_video()
    
    #obj = input("Enter an object: ")

    #collect data infinitely
    while True:

        img, img2 = od.gather_camdata(ipv4_url)
        ##od.gather_camdata()
        #img, markers_list, classIds, indices, bboxes = od.classify_objects(img)
        #img2, markers2, classIds2, indices2, bboxes2 = od.classify_objects(img2)

        ##return the coords of all 4 corner markers. this is the code 
        ##for object detection on our table grid
        #tl, tr, bl, br = od.find_markers(markers_list)
        #object = od.select_object(classIds, indices, bboxes, "apple")
        #od.locate_object(tl, tr, object)

        od.display(img, img2)
        cv2.waitKey(1)




