#include <initiator.cpp>
#include <vector>

// ZERO is black.
// ONE is white.

int main()
{
    // BEGIN OF SETTING THE ACCUMULATOR FOR 5.

    Mat* trainingSet_5 = new Mat[20];
    trainingSet_5 = init5TrainingSet(trainingSet_5);
    trainingSet_5 = grayToBin_5(trainingSet_5);

    double** accumulator_5 = setArray(accumulator_5);

    accumulator_5 = generateAcc(trainingSet_5);

    // END OF SETTING THE ACCUMULATOR FOR 5.


    // BEGIN OF SETTING THE ACCUMULATOR FOR 6.

    Mat* trainingSet_6 = new Mat[20];
    trainingSet_6 = init6TrainingSet(trainingSet_6);
    trainingSet_6 = grayToBin_6(trainingSet_6);

    double** accumulator_6 = setArray(accumulator_6);

    accumulator_6 = generateAcc(trainingSet_6);


    // END OF SETTING THE ACCUMULATOR FOR 6.

    // Getting total probability of each accumulator => P(X1...Xn).
    int totalProb_5 = getPrior(accumulator_5);
    int totalProb_6 = getPrior(accumulator_6);


    //Getting P(X1...Xn|Y). by applying in both 2 accumulators on Y.
    Mat testImg;
    initImage(testImg, "/home/belal/Desktop/5/2.jpg");

    double* myVals = new double[2];
    myVals = getLikeliHood(testImg, accumulator_5, accumulator_6);
    // Now I have P(X1..Xn|5) at 0 & P(X1..Xn|6) at 1


    //Calculate for 5
    double image5 = (( myVals[0] * 0.5 ) + 1) / (totalProb_5 + 2);
    //Calculate for 6
    double image6 = (( myVals[1] * 0.5 ) + 1) / (totalProb_6 + 2);

    if(image5 > image6)
        cout << "HALLELUJAH, Your number is 5" << endl;
    else
        cout << "You're lucky that I found it in my database. It's 6" << endl;


    waitKey(0);
    return 0;
}
