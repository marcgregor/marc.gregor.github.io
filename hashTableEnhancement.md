# Artifact Two - Algorithms and Data Structure: ABCU Hash Table Data Structure
[Link to the original and enhanced artifact](https://github.com/marcgregor/marcgregor.github.io/tree/main/Artifact%20Two%20-%20ABCU)

## Briefly Describe the Artifact. What is it? When was it Created?
Originally, it was a binary search tree created in C++ for CS300 back in 23EW4. Used in the ABCU project two, it created a structure of various courses that a university offered. It gave the user the ability to load the courses, print all courses alphabetically, and search for a specific course – this will also show its required prerequisites. This was a program designed without security in mind, and why it’s so important to fixate on secure coding from the start. Smart pointers weren’t used, and the pointers weren’t deallocated propery, which would cause massive memory leak problems in the real world. I had to “patch” security, making it feel janky – had security been a main priority from the start, the code would not only be written more efficiently, it would feel more natively secure.
## Justify the Inclusion of the Artifact in your ePortfolio. Why did you Select this Item? What Specific Components of the Artifact Showcase your Skills and Abilities in Software Development? How was the Artifact Improved?
My main justification in including this artifact is that I thought I could not only increase the overall efficiency of the algorithm by moving to a hash table, but I could also give the users additional options to manipulate the data. I was able to showcase my ability of adapting to any software need – after all, I moved from a binary search tree to a hash table – by managing the structure and algorithm change without it becoming too overwhelming. Adding more complexity to the program by giving users the options to add or delete a course showed that I have considerable skill and knowledge using C++. The overall efficiency of the program is improved with a hash table because the average time complexity for a hash table is O(1) when it comes to things like searching, insertion, and deletion, beating a binary search tree’s average time complexity of O(log(n)). On top of that, I fixed some concerning security issues that came with the original project. While not inherently dangerous, using namespace std can cause some ambiguity, so I removed it. More importantly, pointers weren’t being deallocated properly, meaning memory leaks were a huge liability.
## Did you Meet the Course Objectives you Planned to Meet with the Enhancement in Module One? Do you have any Updates to your Outcome-Coverage Plans?
The following course objectives have been met:
 
### Outcome 1 - Employ strategies for building collaborative environments that enable diverse audiences to support organizational decision making in the field of computer science: 
I provided simple but concise in-line comments that provided not only the reasoning behind writing the code, but also the purpose of each main code block. I also used comments to split up the coding into different sections, such as initial setup and functions for user readability. I took the requirements given, gathered any additional information needed, and built the software around the requirements, while writing a narrative explaining the whys and hows of the enhancement. Finally, I wrote a reflective piece at the end of each enhancement to discuss my overall experience with the enhancement.
### Outcome 2 - Design, develop, and deliver professional-quality oral, written, and visual communications that are coherent, technically sound, and appropriately adapted to specific audiences and contexts:
These comments also provide a line of communication between the reader and developer, and this narrative allows the reader to understand what the artifact was, why I chose it, and also understand the improvements of the artifact. On top of that, the reflection describes my experience and explains what I considered to be the best overall practice to accomplishing the enhancement.
### Outcome 3 - Design and evaluate computing solutions that solve a given problem using algorithmic principles and computer science practices and standards appropriate to its solution, while managing the trade-offs involved in design choices:
Outcome 3 is met for two main reasons – a more efficient structure is created and added complexity is implemented to give users more options. I used a flowchart to detail some of the added features in the enhancement plan. I programmed in a hash table to solve logic problems and increase efficiency, increasing the time complexity from O(log(n)) to O(1). I added complexity to the program, allowing users more options to manipulate the data. I used my reflection to discuss my experiences with the project in creating a more efficient system, as well as some issues I ran into.
### Outcome 5 - Develop a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources:
Security was a focus in this enhancement. I no longer implemented “using namespace std” to prevent any potential issues from ambiguity. I cleaned up any pointers that may have been causing memory leaks. I addressed these two original design flaws of the architecture and helped mitigate these possible vulnerabilities. There are also catches in place to make sure input data is valid. I discussed the security issues beforehand and why it was so important to fixate on security.
## Reflect on the Process of Enhancing and/or Modifying the Artifact. What did you Learn as you were Creating it and Improving it? What Challenges did you Face?
It was clunky and frustrating at first trying to convert the binary search tree into a hash table, but once I was successful in the transition, I was able to add the added features without much issue. I learned that there are a lot more moving pieces in a hash table, and it took more than 150 additional lines of code, but I found it interesting to see the relationship between the two structures and how they’re built. My biggest challenge was trying to successfully set up the key. The key is an integer, and since the course ID was alphanumeric (ABCD123), I had to turn it into an arbitrary integer by using ASCII values of the string.

# Original Artifact
![image](https://github.com/marcgregor/marcgregor.github.io/assets/120348789/4dad3a81-cf37-4185-81ca-5f36766672c5)

Here is the menu for the original course planner. As shown, there are 4 options - load the data (should say "load courses"; a typo on the original artifact), print all courses in alphabetical order, search for a specific course and any prerequisites, and to exit the program. 

```cpp

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

```
Here is the Node structure and class for the original binary search tree. The struct Node contains the tree nodes used to traverse data - this includes a object of the courses, pointers to both the left and right nodes, the default constructor (where the left and right nodes are set to null), and a parameterized constructor intialized with a course. The BinarySearchTree class contains the members and functions that create the BST, such as the root node, and methods to add a node and to print the course list.
# Flowchart for Planned Enhancement of Additional Options
![flowchart](https://github.com/marcgregor/marcgregor.github.io/assets/120348789/b8dcc649-bdbb-40cf-9fd4-9428f69c8292)

Here, the 4 main options other than loading courses and exiting the program is shown. The two new features, add and remove a course are planned out - insert() is called when adding a course, and remove() is called when requesting to delete a course. If the user entered correct data for adding a course, it'll get added to the list; otherwise, an error message pops up letting the user know that the data entered was incorrect, such as missing a field. As for removing data, if it exists, it'll get removed; otherwise, it lets the user know that it never existed.
# Enhanced Artifact
![image](https://github.com/marcgregor/marcgregor.github.io/assets/120348789/f3b06d08-dc2c-4583-824a-10a8b9a00d7e)

The enhanced menu options are now present. It now correctly says "load courses", and the two new features have been added to the selection screen.
```cpp

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

```
This is the code for adding a course to the list. If the user selects the option, the case for '4' executes, which then asks the user for the course ID of the new course. After that, the user then enters the course description; at this point, the program asks if there are any prerequisites, in which a if/else statement executes based on the input. Otherwise, if something was incorrect, an error message lets the user know.
