//============================================================================
// Name        : ArtifactTwoEnhancement.cpp
// Description : Enhancement Two: Algorithms and Data Structures
//               Previously: Binary Search Tree with option to print
//               course list and search for a specific course.
// Author      : Marc Gregor
// Contact     : marc.gregor@snhu.edu
// Date        : 5 December 2023
// Version     : 3.0 - Final Enhanced Edition
//
// Purpose     : My intent in this enhancement was to showcase my various
//               skills and abilities in creating a more efficient algorithm
//               as well as a more complex data structure. Therefore, I
//               decided to change from previous BST to a hash table, as the
//               average time complexity of a hash table is O(1), while the
//               average time complexity of a binary search tree is O(log(n)).
//               It took skill in understanding the concepts of data structures
//               written in C++, as well as my ability to write efficient coded
//               to provide more complex options for the user.
//
// Function    : This program uses a hash table to store courses that a
//               university offers. Loading the courses from a CSV file
//               via the loadCourses() method, it then stores them in a
//               hash table. There are functions that allow the user to
//               search for a course, print out the entire list, as well
//               as adding and removing courses.
//============================================================================


#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>


// Default size of the table
const unsigned int DEFAULT_SIZE = 179;


// The structure that holds the course objects, which includes a vector to hold all of the individual prerequisites
struct CourseObject {
	std::string courseId;
	std::string courseDesc;
	std::vector<std::string> preReq;
};

//============================================================================
// Hash Table class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a hash table with chaining.
 */
class HashTable {

private:
	// Define structures to hold courses
	struct Node {
		CourseObject courseObject;
		unsigned int key;
		Node* next;

		// default constructor
		Node() {
			key = UINT_MAX;
			next = nullptr;
		}

		// initialize with a course
		Node(CourseObject aCourse) : Node() {
			courseObject = aCourse;
		}

		// initialize with a course and a key
		Node(CourseObject aCourse, unsigned int aKey) : Node(aCourse) {
			key = aKey;
		}
	};

	std::vector<Node> nodes;

	unsigned int tableSize = DEFAULT_SIZE;

	unsigned int hash(std::string courseId);

public:
	HashTable();
	HashTable(unsigned int size);
	virtual ~HashTable();
	void insert(CourseObject courseObject);
	void Remove(std::string courseId);
	void printSampleSchedule();
	CourseObject printCourseInformation(std::string courseId);
};

/**
 * Default constructor
 */
HashTable::HashTable() {
	// Initalizes existing node structure up above with .resize() tableSize 
	nodes.resize(tableSize);

}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(unsigned int size) {
	// invoke local tableSize to size with this->
	this->tableSize = size;

	// Resizes node with .resize()
	nodes.resize(tableSize);
}

/**
 * Destructor
 */
HashTable::~HashTable() {
	// Uses .erase() method to erase nodes from the beginning element with .begin()
	nodes.erase(nodes.begin());
}


/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(std::string courseId) {
	unsigned long key = 5381;
	// Since the course ID has string characters, they need to be converted beforehand
	for (size_t i = 0; i < courseId.size(); ++i)
		key = 33 * key + (unsigned char)courseId[i];
	// Returns a modulo calculation between the key and size of the table
	return key % tableSize;
}

/**
 * Insert a course
 *
 * @param course The course to insert
 */
void HashTable::insert(CourseObject courseObject) {
	// Sets the key to the just finished hash method with courseId parameter, since the courseId will be unique.
	unsigned key = hash(courseObject.courseId.c_str());

	// This retrieves the node pointer at the key reference
	Node* node = &(nodes.at(key));

	// If the node pointer comes back null
	if (node == nullptr) {
		// Initialize a new node and set it to the position of the key
		Node* newNode = new Node(courseObject, key);
	}
	else {
		// If node key is empty and set to UINT_MAX
		if (node->key == UINT_MAX) {
			// Set node key, course, and next to key, course, and null, respectfully
			node->key = key;
			node->courseObject = courseObject;
			node->next = nullptr;
		}
		// else when the node is not empty - aka - a collision has occured
		else {
			// While the next node is occupied
			while (node->next != nullptr) {
				// It is set to the next node and loops
				node = node->next;
			}
			// Adds new node to the end
			node->next = new Node(courseObject, key);
		}
	}
}

void HashTable::printSampleSchedule() {
	// A for loop uses an iterator starting at the begining of the vector and runs while it isn't at the end
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		//   If the iterator key is not equal to UINT_MAX
		if (it->key != UINT_MAX) {
			// It will print out the courseID and description
			std::cout << it->courseObject.courseId << ", " << it->courseObject.courseDesc << std::endl;
			// Node is equal to the next iterator
			Node* node = it->next;

			// While the node not equal to null
			while (node != nullptr) {
				// It will print out the courseID and description
				std::cout << node->courseObject.courseId << ", " << node->courseObject.courseDesc << std::endl;
				// The node is equal to the next node
				node = node->next;
			}
		}
	}
}

/**
 * Remove a course
 *
 * @param courseId The course id to search for
 */
void HashTable::Remove(std::string courseId) {
	// Set the key equal to the hash method with courseId parameter
	unsigned key = hash(courseId.c_str());
	// erase() erases the node begin and key
	nodes.erase(nodes.begin() + key);
}

/**
 * Search for the specified courseId
 *
 * @param courseId The course id to search for
 */
CourseObject HashTable::printCourseInformation(std::string courseId) {
	CourseObject courseObject;
	// Set the key equal to the hash method with courseId parameter
	unsigned key = hash(courseId.c_str());
	// This retrieves the node pointer at the key reference
	Node* node = &nodes.at(key);

	// If node is not null and the node key is not equal to UINT_MAX and the node courseId is the same as the
	// searched courseId
	if (node != nullptr && node->key != UINT_MAX && node->courseObject.courseId.compare(courseId) == 0) {
		// Return node course
		return node->courseObject;
	}
	// if no entry found for the key
	if (node == nullptr || node->key == UINT_MAX) {
		// Return course
		return courseObject;
	}
	// While node is not equal to nullptr
	while (node != nullptr) {
		// If the current node key matches, return it
		if (node->key != UINT_MAX && node->courseObject.courseId.compare(courseId) == 0) {
			return node->courseObject;
		}
		// Node is equal to next node
		node = node->next;
	}
	return courseObject;
}

/**
 * Display the course information to the console (std::out)
 *
 * @param course struct containing the course info
 */
void displayCourse(CourseObject courseObject) {
	std::cout << courseObject.courseId << ", " << courseObject.courseDesc << std::endl;

	// loop through prerequisites vector to print out each
	if (courseObject.preReq.size() > 0) {
		std::cout << "Prerequisites: ";

		for (unsigned int x = 0; x < courseObject.preReq.size(); ++x) {

			std::cout << courseObject.preReq[x];

			// prevents trailing comma after last prerequisite is printed out
			if (x != courseObject.preReq.size() - 1) {
				std::cout << ", ";
			}
		}
	}
}

void loadCourses(std::string csvPath, HashTable* hashTable) {
	// The endline is for readability and then prints out a message saying that the file is being loaded
	std::cout << std::endl;
	std::cout << "Loading CSV file: " << csvPath << std::endl;
	// Variable to hold the file, and two separate vectors that hold the courseIds and prerequisites
	std::ifstream csvFile;
	std::vector <std::string> idList;
	std::vector<std::string> prerequisites;

	// Open the stream with the path passed by the user
	csvFile.open(csvPath);

	// Insert data into courses
	if (csvFile.is_open()) {
		// Holds line data
		std::string line;
		// Read file line by line using while loop
		while (getline(csvFile, line)) {
			// Vector that holds each line and its child variable. SS variable to split
			std::vector <std::string> lineData;
			std::string data;
			std::stringstream ss(line);

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
				std::vector <std::string> preReqChecks;
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
				hashTable->insert(courseObject);
			}
			// Else a error message prints out saying a line didn't contain enough information
			else {
				std::cout << "Line Error - a line did not contain enough information" << std::endl;
			}

		}
		// For loop that checks if a prerequisite actually exists on the course list
		for (unsigned int i = 0; i < prerequisites.size(); i++) {
			if (find(idList.begin(), idList.end(), prerequisites[i]) == idList.end()) {
				std::cout << "Prerequisite " << prerequisites[i] << " not on schedule." << std::endl;
				break;
			}
		}
	}
	// Else it prints out an error message saying the file path isn't correct
	else {
		std::cout << "That is not a correct file option! Please try again" << std::endl;
	}
	// Prints out the number of courses loaded into the program and then closes the file.
	std::cout << "There are " << idList.size() << " total courses loaded into the program" << std::endl << std::endl;
	csvFile.close();
}


int main() {
	// Variables for things such as the file path, hash table pointer object, CourseObject object, menu choice, and search
	std::string csvPath;
	HashTable* courseTable;
	courseTable = new HashTable();
	CourseObject courseObject;
	int choice = 0;
	std::string courseSearch;
	std::string idInput;
	std::string descInput;
	std::string prereqInput;
	char preOption;

	std::cout << "Welcome to the ABCU Course Planner!" << std::endl;
	// Menu loops until the user chooses 6
	while (choice != 6) {
		std::cout << "Menu:" << std::endl;
		std::cout << "  1. Load Courses" << std::endl;
		std::cout << "  2. Print All Courses" << std::endl;
		std::cout << "  3. Search For a Course and its Prerequisites" << std::endl;
		std::cout << "  4. Add Course" << std::endl;
		std::cout << "  5. Remove Course" << std::endl;
		std::cout << "  6. Exit Program" << std::endl;
		std::cout << "Please enter your choice: ";
		std::cin >> choice;
		// Uses a switch case to interact with user's input above
		switch (choice) {

		// Choosing 1 will ask the user for the file path and will call loadCoarses() to load the courses
		case 1:
			// Normally, the user would be asked the file name and location in order for the program to access it.
			// However, to save time for this project, I hard coded in the file name, so the program automatically
			// loads the file when option one is chosen.
			csvPath = "ABCU_Advising_Program_Input.csv";
			loadCourses(csvPath, courseTable);
			break;

		// Choosing 2 will simply call PrintSampleSchedule() to print out all of the courses (no prerequisites)
		case 2:
			std::cout << std::endl;
			courseTable->printSampleSchedule();
			std::cout << std::endl;
			break;

		// Choosing 3 will ask the user to enter the requested course ID and calls printCourseInformation() to
		// start the search. If found, it calls displayCourse() to display the info and if the course ID is not
		// found, it prints out a message letting the user know
		case 3:
			std::cout << "Please enter the course ID: ";
			std::cin >> courseSearch;
			std::cout << std::endl;
			// calling toupper() capitalizes the first 4 characters of the input, effectively making it case insensitive
			courseSearch[0] = toupper(courseSearch[0]);
			courseSearch[1] = toupper(courseSearch[1]);
			courseSearch[2] = toupper(courseSearch[2]);
			courseSearch[3] = toupper(courseSearch[3]);
			courseObject = courseTable->printCourseInformation(courseSearch);
			if (!courseObject.courseId.empty()) {
				displayCourse(courseObject);
			}
			else {
				std::cout << "Course ID " << courseSearch << " was not found." << std::endl;
			}
			std::cout << std::endl;
			break;

		// Selecting four will give the user the ability to add a course
		case 4:
			// idInput grabs the user input of the ID
			std::cout << "Please enter the course ID: " << std::endl;
			std::cin >> idInput;
			// Like above, calling toupper() capitalizes the first four letters, keeping it uniform with the others
			idInput[0] = toupper(idInput[0]);
			idInput[1] = toupper(idInput[1]);
			idInput[2] = toupper(idInput[2]);
			idInput[3] = toupper(idInput[3]);
			// Grabs the description of the user input
			std::cout << "Please enter the course description: " << std::endl;
			std::cin >> descInput;
			// The user is asked if the course has a prerequisite
			std::cout << "Does the course have a prerequisite? Y/N" << std::endl;
			std::cin >> preOption;
			// If it does, the user enters the prerequisite
			if (preOption == 'Y' || preOption == 'y') {
				std::cout << "Please enter the prerequisites: " << std::endl;
				std::cin >> prereqInput;
				// The inputted data is then set to the course objects, as well as the prerequisite being pushed into
				// the prereq vector
				courseObject.courseId = idInput;
				courseObject.courseDesc = descInput;
				courseObject.preReq.push_back(prereqInput);
				// Add new course to courses
				courseTable->insert(courseObject);
			}
			// If it doesn't, data is set to course objects
			else if (preOption == 'N' || preOption == 'n') {
				courseObject.courseId = idInput;
				courseObject.courseDesc = descInput;
				// Add new course to courses
				courseTable->insert(courseObject);
			}
			// If anything else is entered, the else executes, sending out a message and returning the user
			// to the main menu.
			else {
				std::cout << "Incorrect option! Reverting back to the main menu." << std::endl;
				break;
			}
			break;

		// Selecting five will give the user the ability to remove a course
		case 5:
			std::cout << "What course would you like to remove?" << std::endl;
			std::cin >> courseSearch;
			std::cout << std::endl;
			// calling toupper() capitalizes the first 4 characters of the input, effectively making it case insensitive
			courseSearch[0] = toupper(courseSearch[0]);
			courseSearch[1] = toupper(courseSearch[1]);
			courseSearch[2] = toupper(courseSearch[2]);
			courseSearch[3] = toupper(courseSearch[3]);
			courseObject = courseTable->printCourseInformation(courseSearch);
			// If the course was found
			if (!courseObject.courseId.empty()) {
				// Remove() is called, removing the course from the table
				courseTable->Remove(courseSearch);
				std::cout << "Course ID: " << courseSearch << " successfully deleted." << std::endl;
			}
			// Otherwise, lets user know the course was not found
			else {
				std::cout << "Course ID " << courseSearch << " was not found." << std::endl;
			}
			break;

		// Choosing 6 will close the loop
		case 6:
			std::cout << std::endl << "Thank you for using the program! Goodbye." << std::endl;
			break;

		// clear() and ignore() help catch any non-int input that would otherwise spin it into an infinite loop
		default:
			std::cout << std::endl << "Incorrect choice. Please try again!" << std::endl;
			std::cin.clear();			
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			
			break;
		}
	}
	return EXIT_SUCCESS;
} 