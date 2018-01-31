#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;


void initImage(Mat &src, string dir){
    src = imread(dir,0);

    if(! src.data )         // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        terminate();
    }

    src = src > 128;
    src.convertTo(src, CV_64F, 1, 0);
    imwrite(dir, src);
    src /= 255;
}


double* getLikeliHood(Mat testImg, double** fiveAccumulator, double** sixAccumulator){
    double* myVals = new double[2];
    myVals[0] = 0;
    myVals[1] = 0;

    for(int i = 0; i < testImg.rows; i++){
        for(int j = 0; j < testImg.cols; j++){
            if(testImg.at<double>(i,j) == 0){
                myVals[0] += 1 - fiveAccumulator[i][j];

                myVals[1] += 1 - sixAccumulator[i][j];

            } else {
                myVals[0] += fiveAccumulator[i][j];

                myVals[1] += sixAccumulator[i][j];

            }

        }
    }

    return myVals;
}


Mat* init5TrainingSet(Mat* imgs){
    string dir = "";
    for(int i = 0; i < 20; i++){
        dir = "/home/belal/DigitRecognizer/5/" + to_string(i+1) + ".jpg";
        imgs[i] = imread(dir, 0);

        if(!imgs[i].data)
            terminate();
    }

    return imgs;
}

Mat* grayToBin_5(Mat* set){
    string dir = "";
    for(int i = 0; i < 20; i++){
        dir = "/home/belal/DigitRecognizer/5/binImgs/" + to_string(i+1) + ".jpg";
        set[i] = set[i] > 128;
        set[i].convertTo(set[i], CV_64F, 1, 0);
        imwrite(dir, set[i]);
        set[i] /= 255;
    }
    return set;
}






Mat* init6TrainingSet(Mat* imgs){
    string dir = "";
    for(int i = 0; i < 20; i++){
        dir = "/home/belal/DigitRecognizer/6/" + to_string(i+1) + ".jpg";
        imgs[i] = imread(dir, 0);

        if(!imgs[i].data)
            terminate();
    }

    return imgs;
}

Mat* grayToBin_6(Mat* set){
    string dir = "";
    for(int i = 0; i < 20; i++){
        dir = "/home/belal/DigitRecognizer/6/binImgs/" + to_string(i+1) + ".jpg";
        set[i] = set[i] > 128;
        set[i].convertTo(set[i], CV_64F, 1, 0);
        imwrite(dir, set[i]);
        set[i] /= 255;
    }
    return set;
}




int getPrior(double** Accumulator){
    int myVal = 1;

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            myVal *= Accumulator[i][j];
        }
    }

    return myVal;
}





double** generateAcc(Mat* set){

    double** accumulator = new double*[50];
    for (int i = 0; i < 50; ++i){
       accumulator[i] = new double[50];
    }

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            accumulator[i][j] = 0;
        }
    }

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 50; j++){
            for(int k = 0; k < 50; k++){
                if(set[i].at<double>(j,k) == 1){
                    accumulator[j][k]++;
                }
            }

        }
    }

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            accumulator[i][j] /= 20;
        }
    }

    return accumulator;
}


void grayToBin(Mat &src, Mat &image){
    src = image > 128;
    src.convertTo(src, CV_64F, 1 , 0);
    //this line is optional but just to check if it's right.
    imwrite("/home/belal/DigitRecognizer/array.jpg", src);
    src /= 255;
}


void printMat(Mat &src){
    for(int i = 0; i < src.rows; i++){
        for(int j = 0; j < src.cols; j++){
            cout << src.at<double>(i,j);
        }
        cout << endl;
    }
}


double** setArray(double** theArray){
    theArray = new double*[50];
    for (int i = 0; i < 50; ++i){
       theArray[i] = new double[50];
    }

    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            theArray[i][j] = 0;
        }
    }

    return theArray;
}
