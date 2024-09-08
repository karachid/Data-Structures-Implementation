typedef struct Node {
	int value;
	struct Node *next;
}Node;

Node* createList(int size);
void push_front(Node** head, int newValue);
void push_back(Node* head, int newValue);
void displayList(Node* head);
void insert(Node** head, int newValue, int x);
int getSize(Node* head);
