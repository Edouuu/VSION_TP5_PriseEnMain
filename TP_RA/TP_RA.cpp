// TP_RA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <Windows.h>
// OpenCV core module (matrices, etc.)
#include <opencv2\core\core.hpp>
// OpenCV highgui: user interface, windows, etc.
#include <opencv2\highgui\highgui.hpp>
// OpenCV image processing (converting to grayscale, etc.)
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\calib3d\calib3d.hpp>
#include <aruco.h>
#include <iostream>

using namespace cv;
using namespace aruco;
using namespace std;

// the ASCCI code for the escape key
#define ESC_KEY 27
#define SPACE_KEY 32

int main(int argc, char** argv)
{
#pragma region Variables
    // Name of the image
    string nomImage;
    Mat myImage;
    // creation d'un detecteur de marqueurs
    MarkerDetector myDetector;
    // For the camera
    VideoCapture cap;
    // A key that we use to store the user keyboard input
    char key;
#pragma endregion

#pragma region Image manuelle
    //cout << "Image name :" << endl;
    //cin >> nomImage;
    //// getting the image
    //Mat myImage = imread(nomImage);
    //if (myImage.empty()) {
    //    cout << "ERROR : Image not found" << endl;
    //}
#pragma endregion

#pragma region Flux Camera

    // Boucle pour ouvrir la camera
    int numCamera = 0;
    while (numCamera != -1 && !cap.isOpened()) {
        cout << "Choix de la camera : ";
        cin >> numCamera;
        cout << endl;
        cap.open(numCamera);
    }
    key = 0;


    // Boucle de lecture du flux de la cam
    while (key != ESC_KEY) {
        // Getting the new image from the camera
        cap.read(myImage);

        // liste de marqueurs : sera remplie par ArUco
        // detect markers and for each one, draw info and its boundaries in the image
        for (auto m : myDetector.detect(myImage)) {
            std::cout << m << std::endl;
            m.draw(myImage);
        }

        // Showing the image in the window
        imshow("Theo et machin", myImage);

        key = waitKey(30);        
    }
    
    
#pragma endregion
    return 0;
}