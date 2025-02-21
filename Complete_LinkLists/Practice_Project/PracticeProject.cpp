#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Book{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	Book* nextBook;
}Book;
bool checkUniqueId(Book* head, int currentId);
void addBook(Book** head, int id, const char* title, const char* author, int publication_year);
void viewBooks(Book* head);
void updateBook(Book* head, int id);
void deleteBook(Book** head, int id);
void searchBooks(Book* head, const char* title);
Book* createNewBook(int id, const char* title, const char* author, int publication_year);
void takeUserInput(int* idFromUser, char* titleFromUser, char* authortFromUser, int* publication_year);
void menu();
int main(void) {
	Book* Library = NULL;
	int isContinue = 1;
	do {
		menu();
		int choice;
		scanf_s("%d", &choice);
		getchar(); //consume \n
		if (choice == 1) {
			int id;
			char title[100];
			char author[100];
			int publication_year;
			printf("Enter your Book ID:\n");
			scanf_s("%d", &id);
			getchar(); //consume \n
			printf("Enter your Book title:\n");
			fgets(title, 100, stdin);
			title[strcspn(title,"\n")] = '\0'; //eliminate \n
			printf("Enter your Book author:\n");
			fgets(author, 100, stdin); //eliminate \n
			author[strcspn(author, "\n")] = '\0';
			printf("Enter your Book publication year:\n");
			scanf_s("%d", &publication_year);
			getchar(); //consume \n
			addBook(&Library, id, title, author, publication_year);
		}
		else if (choice == 2) {
			viewBooks(Library);
		}
		else if (choice == 3) {
			printf("Enter your new id to update:\n");
			int id;
			scanf_s("%d", &id);
			getchar(); // consume \n
			updateBook(Library, id);
		}
		else if(choice == 4){
			printf("Enter your new id to delete:\n");
			int id;
			scanf_s("%d", &id);
			getchar(); // consume \n
			deleteBook(&Library, id);
		}
		else if(choice ==5){
			printf("Enter your new title to search:\n");
			char title[100];
			fgets(title, 100, stdin);
			title[strcspn(title, "\n")] = '\0';
			searchBooks(Library, title);
		}
		else if (choice == 6) {
			isContinue = 0;
		}
		else {
			printf("Invalid options!\n");
		}
	} while (isContinue != 0);
	return 0;
}
Book* createNewBook(int id, const char* title, const char* author, int publication_year) {
	Book* newBook = (Book*)malloc(sizeof(Book)); //allocate memory
	if (newBook == NULL) {
		printf("NO MEMORY\n");
		exit(EXIT_FAILURE);
	}
	newBook->id = id;
	strcpy_s(newBook->title, sizeof(newBook->title), title);
	strcpy_s(newBook->author, sizeof(newBook->author), author); 
	newBook->publication_year = publication_year;
	newBook->nextBook = NULL;
	return newBook;
}
bool checkUniqueId(Book* head, int currentId) {
	while (head != NULL) {
		if (currentId == head->id) {
			return true;
		}
		head = head->nextBook;
	}
	return false;
}
void addBook(Book** head, int id, const char* title, const char* author, int publication_year) {
	printf("\n----------------Add-----------------\n");
	if (checkUniqueId(*head, id) == false) {
		Book* newBook = createNewBook(id, title, author, publication_year);
		if (*head == NULL) {
			// this will be the first node
			newBook->nextBook = *head;
			*head = newBook;

		}
		else {
			Book* prev = *head; // assign head node another pointer to traverse through link list
			while (prev->nextBook != NULL) {
				prev = prev->nextBook;
			}
			//to this point prev pointer already at the end of link list so we can assign next node to new node that we have just created
			prev->nextBook = newBook; 
		}
	}
	else
	{
		printf("\nYour id is not unique!\n");
		return;
	}

}
void viewBooks(Book* head) {
	printf("\n----------------View-----------------\n");
	int i = 1;
	if (head == NULL) {
		printf("\nThere are no book in database\n");
		return;
	}
	else {
		while (head != NULL) {
			printf("------------------------------\n");
			printf("No.%d\n", i);
			printf("Id of the book: %d\n", head->id);
			printf("Author of the book : %s\n", head->author);
			printf("Title of the book : %s\n", head->title);
			printf("Year publish of the book : %d\n", head->publication_year);
			printf("------------------------------\n");
			i++;
			head = head->nextBook;
		}
	}
}
void takeUserInput(int* idFromUser, char* titleFromUser, char* authortFromUser, int* publication_year) {
	printf("Enter your new id:\n");
	scanf_s("%d", idFromUser);
	getchar(); //consume \n
	printf("Enter your new title:\n");
	gets_s(titleFromUser,100);
	printf("Enter your new author:\n");
	gets_s(authortFromUser,100);
	printf("Enter your publication year:\n");
	scanf_s("%d", publication_year);
	getchar(); //consume \n

}

void updateBook(Book* head, int id) {
	printf("\n----------------Update-----------------\n");
	bool foundId = false; // by default i will set this value to false, because we have not started search yet
	while (head != NULL) {
		if (head->id == id) {
			foundId = true;
			int idFromUser;
			char titleFromUser[100];
			char authortFromUser[100];
			int publication_year;
			takeUserInput(&idFromUser, titleFromUser, authortFromUser, &publication_year);
			head->id = idFromUser;
			strcpy_s(head->title, sizeof(head->title), titleFromUser);
			strcpy_s(head->author, sizeof(head->title), authortFromUser);
			head->publication_year = publication_year;


		}
		head = head->nextBook;
	}
	if (foundId == false) {
		printf("Error, We do not have that id in library\n");
		return;
	}
}
void deleteBook(Book** head, int id) {
	printf("\n----------------Delete-----------------\n");
	bool isFound = false;// by default i will set this value to false, because we have not started search yet
	Book* currentPointer = *head;
	Book* prevPointer = NULL;
	// Case 1: nothing
	if (*head == NULL) {
		printf("\nDo not have anything to search!\n");
		return;
	}
	//case 2: onely 1
	else if (currentPointer->nextBook == NULL && currentPointer->id == id) {
		isFound = true;
		*head = NULL;
		free(currentPointer);
	}
	
	// Case 3: over 2
	else if (currentPointer->nextBook != NULL) {
		while (currentPointer != NULL && currentPointer->id != id) {
				prevPointer = currentPointer;
				currentPointer = currentPointer->nextBook;
		}
		currentPointer==NULL ? isFound = false : isFound = true; //because if current point equal to null, it mean that the currentPointer already iterated to the end of link lists without matching id
		// first element need to be deleted
		if (prevPointer == NULL) {
			(*head) = currentPointer->nextBook;
			free(currentPointer);
		}
		else if(currentPointer !=NULL) {
			// /because if current point equal to null, it mean that the currentPointer already iterated to the end of link lists without matching id
			// this will make sure, we will delete the node that we actually have in link list
			prevPointer->nextBook = currentPointer->nextBook;
			free(currentPointer);
		}

	}

	isFound == true ? printf("we found your book id and deleted it\n") : printf("we can not found your book id!\n");
}
void searchBooks(Book* head, const char* title) {
	printf("\n----------------Search-----------------\n");
	bool isFound = false; // by default i will set this value to false, because we have not started search yet
	while (head != NULL) {
		char* checkSubString = strstr(head->title, title);
		if (checkSubString) {
			isFound == true; //update because in this case, we already found
			printf("\nList of searching\n");
			printf("------------------------------\n");
			printf("Id of the book: %d\n", head->id);
			printf("Author of the book : %s\n", head->author);
			printf("Title of the book : %s\n", head->title);
			printf("Year publish of the book : %d\n", head->publication_year);
			printf("------------------------------\n");
			
		}
		head = head->nextBook;
	}
	if (isFound == false) {
		printf("We do not have the book that you are searching!\n");
	}
}
void menu() {
	printf("-----------------Menu-----------------\n");
	printf("1. Add Book!\n");
	printf("2. View Book!\n");
	printf("3. Update Book\n");
	printf("4. Delete Book!\n");
	printf("5. Search Book!\n");
	printf("6. Exit!");
	printf("\n----------------------------------\n");
	printf("Your choice:\n");
}