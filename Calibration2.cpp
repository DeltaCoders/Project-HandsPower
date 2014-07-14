#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

struct BGR{
	int B;
	int G;
	int R;
}low, high;

Point thumb(420, 280), index(450, 180), middle(480, 170), ring(510, 180), little(540, 200), palm_bottom(460, 340), palm_mid(530, 280), palm_top(480, 260);

//Function prototypes
void mark(Mat);
void saveBGR(Mat);
void loadBGR();

int main(){
	Mat webcam_mat;
	VideoCapture webcam(0);
	bool status = false;

	if (webcam.isOpened()){
		status = true;
		namedWindow("Calibration", WINDOW_AUTOSIZE);// Create a window for display.
		waitKey(1000);//WAIT Camera connection, instead get exception thrown
	}

	while (status){
		webcam.read(webcam_mat);
		flip(webcam_mat, webcam_mat, 1);
		rectangle(webcam_mat, Point(10, 25), Point(520, 60), Scalar(255, 255, 255), CV_FILLED);
		putText(webcam_mat, "Press S to save cfg, L to load an old one", Point(10, 50), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(200, 100, 0), 1, 8, false);
		mark(webcam_mat);
		imshow("Calibration", webcam_mat);

		switch (waitKey(15)){

		case 83:
		case 115:
			saveBGR(webcam_mat);
			break;

		case 76:
		case 108:
			loadBGR();
			break;
		case 27:
			//release all resource, break loop
			status = false;
			break;
		}
	}
	return 0;
}

void mark(Mat matrix){
	Size side(6, 6);
	Point offset(3, 3);
	Rect thumb_mark(thumb - offset,  side);
	Rect index_mark(index - offset, side);
	Rect middle_mark(middle - offset, side);
	Rect ring_mark(ring - offset, side);
	Rect little_mark(little - offset, side);
	Rect palm_bottom_mark(palm_bottom - offset, side);
	Rect palm_mid_mark(palm_mid - offset, side);
	Rect palm_top_mark(palm_top - offset, side);
	
	Scalar rect_color(0, 255, 125);

	rectangle(matrix, thumb_mark, rect_color, 2);
	rectangle(matrix, index_mark, rect_color, 2);
	rectangle(matrix, middle_mark, rect_color, 2);
	rectangle(matrix, ring_mark, rect_color, 2);
	rectangle(matrix, little_mark, rect_color, 2);
	rectangle(matrix, palm_bottom_mark, rect_color, 2);
	rectangle(matrix, palm_mid_mark, rect_color, 2);
	rectangle(matrix, palm_top_mark, rect_color, 2);

}
void saveBGR(Mat matrix){

	BGR thumb_BGR, index_BGR, middle_BGR, ring_BGR, little_BGR, palm_bottom_BGR, palm_mid_BGR, palm_top_BGR;
	low.B = 0;
	low.G = 0;
	low.R = 0;
	high.B = 255;
	high.G = 255;
	high.R = 255;
	Vec3b color[8];

	//RETRIEVE ALL VALUE
	color[0] = matrix.at<Vec3b>(Point(523, 303));
	color[1] = matrix.at<Vec3b>(Point(553, 303));
	color[2] = matrix.at<Vec3b>(Point(583, 303));
	color[3] = matrix.at<Vec3b>(Point(533, 223));
	color[4] = matrix.at<Vec3b>(Point(553, 223));
	color[5] = matrix.at<Vec3b>(Point(573, 223));
	color[6] = matrix.at<Vec3b>(Point(543, 143));
	color[7] = matrix.at<Vec3b>(Point(553, 143));
	color[8] = matrix.at<Vec3b>(Point(563, 143));



	thumb_BGR.B = color[0][0];
	thumb_BGR.G = color[0][1];
	thumb_BGR.R = color[0][2];

	index_BGR.B = color[1][0];
	index_BGR.G = color[1][1];
	index_BGR.R = color[1][2];

	middle_BGR.B = color[2][0];
	middle_BGR.G = color[2][1];
	middle_BGR.R = color[2][2];

	ring_BGR.B = color[3][0];
	ring_BGR.G = color[3][1];
	ring_BGR.R = color[3][2];

	little_BGR.B = color[4][0];
	little_BGR.G = color[4][1];
	little_BGR.R = color[4][2];

	palm_bottom_BGR.B = color[5][0];
	palm_bottom_BGR.G = color[5][1];
	palm_bottom_BGR.R = color[5][2];

	palm_mid_BGR.B = color[6][0];
	palm_mid_BGR.G = color[6][1];
	palm_mid_BGR.R = color[6][2];

	palm_top_BGR.B = color[7][0];
	palm_top_BGR.G = color[7][1];
	palm_top_BGR.R = color[7][2];

	for (int i = 0; i < 8; i++){
		cout << (int)color[i][0] << "\t" << (int)color[i][1] << "\t" << (int)color[i][2] << endl;
	}

	//AVG VALUE
	low.B = 255;
	low.G = 255;
	low.R = 255;
	high.B = 0;
	high.G = 0;
	high.R = 0;
	for (int i = 0; i < 8; i++){
		if (low.B > color[i][0]){
			low.B = color[i][0];
		}
		if (low.G > color[i][1]){
			low.G = color[i][1];
		}
		if (low.R > color[i][2]){
			low.R = color[i][2];
		}
		if (high.B < color[i][0]){
			high.B = color[i][0];
		}
		if (high.G < color[i][1]){
			high.G = color[i][1];
		}
		if (high.R < color[i][2]){
			high.R = color[i][2];
		}
	}

	//FILE SAVE
	ofstream write_config;
	write_config.open("C:\\BGR.cfg");
	write_config << low.B << "*" << low.G << "*" << low.R << "*" << high.B << "*" << high.G << "*" << high.R;
	write_config.close();
	cout << "Configuration saved: " << low.B << "*" << low.G << "*" << low.R << "*" << high.B << "*" << high.G << "*" << high.R << endl;
}

void loadBGR(){
	int saveCfg[6];
	int i = 0;
	ifstream read_config("C:\\BGR.cfg");
	string line;

	if (read_config.is_open()){
		while (getline(read_config, line, '*')){

			saveCfg[i] = atoi(line.c_str());
			i++;
		}
		read_config.close();
		low.B = saveCfg[0];
		low.G = saveCfg[1];
		low.R = saveCfg[2];
		high.B = saveCfg[3];
		high.G = saveCfg[4];
		high.R = saveCfg[5];

		cout << "Configuration loaded: " << low.B << "*" << low.G << "*" << low.R << "*" << high.B << "*" << high.G << "*" << high.R << endl;
	}
	else{
		cout << "Unable to open file (have you saved it by pressing \"S\"?)\n";
	}
}
