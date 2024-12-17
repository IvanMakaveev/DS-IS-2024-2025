#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct Node
{
	T data;
	vector<Node<T>*> children;

	Node(T data) : data(data) {}
};

template <class T>
void print(Node<T>* root)
{
	cout << root->data << " ";

	for (int i = 0; i < root->children.size(); i++)
		print(root->children[i]);
}

template <class T>
void free(Node<T>* root)
{
	for (int i = 0; i < root->children.size(); i++)
		free(root->children[i]);

	delete root;
}

template <class T>
bool contains(Node<T>* root, T element)
{
	int size = root->children.size();

	if (root->data == element)
    {
		return true;
    }

	for (int i = 0; i < size; i++)
	{
		if (contains(root->children[i], element))
        {
            return true;
        }
	}

	return false;
}

template <class T>
int sum(Node<T>* root)
{
	int sum = root->data;

	for (int i = 0; i < root->children.size(); i++)
    {
		sum += sum(root->children[i]);
    }

	return sum;
}

template <class T>
T maxT(Node<T>* root)
{
	T maxEl = root->data;

	for (int i = 0; i < root->children.size(); i++)
    {
		maxEl = max(maxEl, maxT(root->children[i]));
    }

	return maxEl;
}

template <class T>
int height(Node<T>* root)
{
	int maxHeight = -1;

	for (int i = 0; i < root->children.size(); i++)
	{
		maxHeight = max(maxHeight, height(root->children[i]));
	}

	return maxHeight + 1;
}

template <class T>
int getNumOfElements(Node<T>* root)
{
	int numOfElements = 1;

	for (int i = 0; i < root->children.size(); i++)
    {
		numOfElements += getNumOfElements(root->children[i]);
    }

	return numOfElements;
}

bool markOccurances(Node<int>* root, vector<bool>& nums, int n)
{
	if (root->data < 1 || root->data > n)
    {
		return false;
    }
	if (nums[root->data - 1])
    {
		return false;
    }

	nums[root->data - 1] = true;

	for (int i = 0; i < root->children.size(); i++)
	{
		if (!markOccurances(root->children[i], nums, n))
        {
            return false;
        }
	}

	return true;
}

bool isPermutation(Node<int>* root)
{
	int size = getNumOfElements(root);
	vector<bool> nums(size);

	return markOccurances(root, nums, size);
}

string word(Node<char>* root, int k)
{
	string wordOnLevel;

	if (root == nullptr)
		return "";
	if (k == 1)
		return wordOnLevel + root->data;

	for (int i = 0; i < root->children.size(); i++)
		wordOnLevel += word(root->children[i], k - 1);
	return wordOnLevel;
}

void fillWords(Node<char>* root, vector<string>& v, string currentWord)
{
	currentWord += root->data;
	if (root->children.size() == 0)
	{
		v.push_back(currentWord);
		return;
	}

	for (int i = 0; i < root->children.size(); i++)
		fillWords(root->children[i], v, currentWord);
}

template<class T>
T sumOfLeaves(Node<T>* root)
{
	int sum = 0;
	if (root->children.size() == 0)
		return root->data;

	for (int i = 0; i < root->children.size(); i++)
		sum += sumOfLeaves(root->children[i]);
	return sum;
}

template <class T>
int getNumOfLeaves(Node<T>* root)
{
	int numOfLeaves = 0;
	if (root->children.empty())
		numOfLeaves++;

	for (int i = 0; i < root->children.size(); i++)
		numOfLeaves += getNumOfLeaves(root->children[i]);

	return numOfLeaves;
}

template <class T>
int maxBranching(Node<T>* root)
{
	int maxBranching = 1;
	int tempBranching = 0;

	for (int i = 0; i < root->children.size(); i++)
		tempBranching = getNumOfLeaves(root->children[i]);

	if (tempBranching > maxBranching)
		maxBranching = tempBranching;

	return maxBranching;
}

std::vector<int> getNextLevel(const std::vector<int>& currLevel, const std::vector<int>& parentArray)
{
	std::vector<int> nextLevel;

	for (int i = 0; i < parentArray.size(); i++)
	{
		int currVertexParent = parentArray[i];
		auto it = std::find(currLevel.begin(), currLevel.end(), currVertexParent);
		if (it != currLevel.end())
			nextLevel.push_back(i);
	}
	return nextLevel;
}

int getHeightParentArray(const std::vector<int>& parentArray)
{
	std::vector<int> currentLevel = { -1 };
	int level = -1;
	while (!currentLevel.empty())
	{
		level++;
		currentLevel = getNextLevel(currentLevel, parentArray);
	}
	return level;
}

int heightHelper(unsigned current, const std::vector<int>& completeArray)
{
    if(current >= completeArray.size())
    {
        return -1;
    }

    return 1 + std::max(heightHelper(2 * current + 1, completeArray),
                        heightHelper(2 * current + 2, completeArray));
}

int getHeightCompleteBinaryArray(const std::vector<int>& completeArray)
{
    return heightHelper(0, completeArray);
}