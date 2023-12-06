// Developer: Marc Gregor
// Binary Search Tree ABCU
// 12 April 2023


#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// The structure that holds the course objects, which includes a vector to hold all of the individual prerequisites
struct CourseObject {
	string courseId;
	string courseDesc;
	vector<string> preReq;
};

// The structure that holds the tree nodes, which include pointers to the left and right node
struct Node {
	CourseObject courseObject;
	Node* left;
	Node* right;
	// Default constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}
	// Initializes Node with a courseObject
	Node(CourseObject aCourseObject) : Node() {
		this->courseObject = aCourseObject;
	}
};

// The actual BST class - contains members and functions to create the binary search tree
class BinarySearchTree {
// The private members of the class
private:
	Node* root;
	void addNode(Node* node, CourseObject courseObject);
	void printSampleSchedule(Node* node);
	//void destruct(Node* node);
// The public members of the class
public:
	BinarySearchTree();
	//virtual ~BinarySearchTree();
	void PrintSampleSchedule();
	void insert(CourseObject courseObject);
	CourseObject printCourseInformation(string courseId);
};

// Default constructor for BST
BinarySearchTree::BinarySearchTree() {
	// The root is equal to nullptr
	root = nullptr;
}

// Destructor for BST
//BinarySearchTree::~BinarySearchTree() {
	//destruct(root);
//}

// Calls private printSampleSchedule() to traverse tree in order
void BinarySearchTree::PrintSampleSchedule() {
	printSampleSchedule(root);
}

// Inserts a course
void BinarySearchTree::insert(CourseObject courseObject) {
	// If root is equal to null
	if (root == nullptr) {
		// Root is set to new node bid
		root = new Node(courseObject);
	}
	// Else
	else {
		// Adds this node via calling addNode()
		this->addNode(root, courseObject);
	}
}

// Recursively adds course to a node
void BinarySearchTree::addNode(Node* node, CourseObject courseObject) {
	// If node is not null and if the node is larger than the compared bidId
	if (node != nullptr && node->courseObject.courseId.compare(courseObject.courseId) > 0) {
		// If there is no left node
		if (node->left == nullptr) {
			// This node becomes the new left node
			node->left = new Node(courseObject);
			return;
		}
		// else 
		else {
			// Recurse addNode() down the left
			this->addNode(node->left, courseObject);
		}
	}
	// else
	else {
		// If there is no right node
		if (node->right == nullptr) {
			// This node becomes the new right node
			node->right = new Node(courseObject);
			return;
		}
		//else
		else {
			// Recurse addNode() down the right
			this->addNode(node->right, courseObject);
		}
	}
}

void loadCourses(string csvPath, BinarySearchTree* bst) {
	// The endline is for readability and then prints out a message saying that the file is being loaded
	cout << endl;
	cout << "Loading CSV file: " << csvPath << endl;
	// Variable to hold the file, and two separate vectors that hold the courseIds and prerequisites
	ifstream csvFile;
	vector <string> idList;
	vector<string> prerequisites;
	
	// Open the stream with the path passed by the user
	csvFile.open(csvPath);

	// Insert data into courses
	if (csvFile.is_open()) {
		// Holds line data
		string line;
		// Read file line by line using while loop
		while (getline(csvFile, line)) {
			// Vector that holds each line and its child variable. SS variable to split
			vector <string> lineData;			
			string data;
			stringstream ss(line);
			
			// While loop splits each line into sections based on the comma. If the section isn't blank, it gets
			// added to the vector
			while (getline(ss, data, ',')) {
				if (data != "") {
					lineData.push_back(data);
				}
			}
			// If the size of the vector is at least 2
			if (lineData.size() >= 2) {	
				// The first section of the line gets pushed into the vector for the IDs
				idList.push_back(lineData[0]);
				// Creates another vector that holds the prereqs that eventually go into courseObject
				vector <string> preReqChecks;
				// For loop that retrieves prerequisites based on vector size
				for (unsigned int i = 2; i < lineData.size(); i++) {
					preReqChecks.push_back(lineData[i]);
					prerequisites.push_back(lineData[i]);

				}
				// All of the obtained data gets placed into CourseObject
				CourseObject courseObject = CourseObject();
				courseObject.courseId = lineData[0];
				courseObject.courseDesc = lineData[1];
				courseObject.preReq = preReqChecks;
				// Add new course to courses
				bst->insert(courseObject);
			}
			// Else a error message prints out saying a line didn't contain enough information
			else {
				cout << "Line Error - a line did not contain enough information" << endl;
			}
			
		}
		// For loop that checks if a prerequisite actually exists on the course list
		for (unsigned int i = 0; i < prerequisites.size(); i++) {
			if (find(idList.begin(), idList.end(), prerequisites[i]) == idList.end()) {
				cout << "Prerequisite " << prerequisites[i] << " not on schedule." << endl;
				break;
			}
		}
	}
	// Else it prints out an error message saying the file path isn't correct
	else {
		cout << "That is not a correct file option! Please try again" << endl;
	}
	// Prints out the number of courses loaded into the program and then closes the file.
	cout << "There are " << idList.size() << " total courses loaded into the program" << endl << endl;
	csvFile.close();
}


void BinarySearchTree::printSampleSchedule(Node* node) {
	// If node is not equal to null
	if (node != nullptr) {
		// inOrder goes to the left node
		printSampleSchedule(node->left);
		// Then it outputs courseID and course description
		cout << node->courseObject.courseId << ", " << node->courseObject.courseDesc << endl;
		// Finally, inOrder goes to right node
		printSampleSchedule(node->right);
	}
}

CourseObject BinarySearchTree::printCourseInformation(string courseId) {
	// Sets current node to root
	Node* current = root;
	

	// Keeps looping while searching downwards until a match is returned
	while (current != nullptr) {
		// If a match is found
		if (current->courseObject.courseId.compare(courseId) == 0) {
			//Returns current course
			return current->courseObject;
		}
		// If course is smaller than current node
		else if (courseId.compare(current->courseObject.courseId) < 0) {
			// Traverses to the left
			current = current->left;
		}
		// else
		else {
			// Traverses to the right
			current = current->right;
		}
	}
	CourseObject courseObject;
	return courseObject;
}

void displayCourse(CourseObject courseObject) {
	cout << courseObject.courseId << ", " << courseObject.courseDesc << endl;
	
	// loop through prerequisites vector to print out each
	if (courseObject.preReq.size() > 0) {
		cout << "Prerequisites: ";

		for (unsigned int x = 0; x < courseObject.preReq.size(); ++x) {

			cout << courseObject.preReq[x];

			// prevents trailing comma after last prerequisite is printed out
			if (x != courseObject.preReq.size() - 1) {
				cout << ", ";
			}
		}
	}
	cout << endl;
}

int main() {
	// Variables for things such as the file path, BST pointer object, CourseObject object, menu choice, and search
	string csvPath;
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	CourseObject courseObject;
	int choice = 0;
	string courseSearch;

	cout << "Welcome to the ABCU Course Planner!" << endl;
	// Menu loops until the user chooses 4
	while (choice != 4) {
		cout << "Menu:" << endl;
		cout << "  1. Load Bids" << endl;
		cout << "  2. Print All Courses Alphabetically" << endl;
		cout << "  3. Search For a Course and its Prerequisites" << endl;
		cout << "  4. Exit" << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
		// Uses a switch case to interact with user's input above
		switch (choice) {
		// Choosing 1 will ask the user for the file path and will call loadCoarses() to load the courses
		case 1:
			cout << "Please enter the full path and file name: ";
			cin >> csvPath;
			loadCourses(csvPath, bst);
			break;
		// Choosing 2 will simply call PrintSampleSchedule() to print out all of the courses (no prerequisites)
		case 2:
			cout << endl;
			bst->PrintSampleSchedule();
			cout << endl;
			break;
		// Choosing 3 will ask the user to enter the requested course ID and calls printCourseInformation() to
		// start the search. If found, it calls displayCourse() to display the info and if the course ID is not
		// found, it prints out a message letting the user know
		case 3:
			cout << "Please enter the course ID: ";
			cin >> courseSearch;
			cout << endl;
			// calling toupper() capitalizes the first 4 characters of the input, effectively making it case insensitive
			courseSearch[0] = toupper(courseSearch[0]);
			courseSearch[1] = toupper(courseSearch[1]);
			courseSearch[2] = toupper(courseSearch[2]);
			courseSearch[3] = toupper(courseSearch[3]);
			courseObject = bst->printCourseInformation(courseSearch);
			if (!courseObject.courseId.empty()) {
				displayCourse(courseObject);
			}
			else {
				cout << "Course ID " << courseSearch << " was not found." << endl;
			}
			cout << endl;
			break;
		// Choosing 4 will close the loop
		case 4:
			cout << endl << "Thank you for using the program! Goodbye." << endl;
			break;
		// clear() and ignore() help catch any non-int input that would otherwise spin it into an infinite loop
		default:			
			cin.clear();
			cin.ignore();
			cout << endl << "Incorrect choice. Please try again!" << endl;
			break;
		}
	}
	// Calls system() to pause the program before exiting in order to view goodbye message
	system("pause");
	return EXIT_SUCCESS;
	
}