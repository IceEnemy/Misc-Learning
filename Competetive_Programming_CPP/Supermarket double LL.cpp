#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct information{
	char id[5];
	char product[20];
	int price;
};

struct Node{
	struct information info;
	int qty;
	struct Node *next;
	struct Node *prev;
};

struct Data{
	struct information info;
	struct Data *next;
	struct Data *prev;
};

struct Data *database = NULL;
struct Node *head = NULL;

struct Data *addData(char id[], char product[], int price){
	struct Data *newData = (struct Data *)malloc(sizeof(struct Data));
	strcpy(newData->info.id,id);
	strcpy(newData->info.product,product) ;
	newData->info.price = price;
	newData->next = newData->prev = NULL;
	return newData;
}

struct Node *addNode(struct information info, int qty){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->info = info;
	newNode->qty = qty;
	newNode->next = newNode->prev = NULL;
	return newNode;
}

struct Data *searchData(char id[]){
	struct Data *temp = database;
	while(temp != NULL){
		if(strcmp(temp->info.id,id) == 0){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void pushData(char id[], char product[], int price){
	struct Data *newData = addData(id,product,price);
	if(database == NULL){
		database = newData;
	}
	else{
		struct Data *temp = database;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newData;
		newData->prev = temp;
	}
}

int add(){
	char input;
	do{
		printf("\nDo you want to add more items? [y] | [n]\n");	
		scanf(" %c",&input);
		getchar();
	}while(input != 'n' && input != 'y');
	if(input == 'n'){
		return 0;
	}
	else{
		return 1;
	}
}

struct Node *unique(char id[]){
	struct Node *temp = head;
	while(temp != NULL && strcmp(temp->info.id,id) != 0){
		temp = temp->next;
	}
	if(temp == NULL){
		return NULL;
	}
	else{
		return temp;
	}
}

int pushBill(struct Data *item){
	int qty;
	system("cls");
	printf("==========================\n");
	printf("Product Id: %s\n",item->info.id);
	printf("Product: %s\n",item->info.product);
	printf("Price: %d$ / item\n",item->info.price);
	printf("==========================\n");
	do{
		printf("Input Qty[>0]: ");
		scanf("%d",&qty);
		getchar();
	}while(qty <= 0);
	struct Node *check = unique(item->info.id);
	if(check == NULL){
		struct Node *newNode = addNode(item->info,qty);
		if(head == NULL){
			head = newNode;
		}
		else{
			struct Node *temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
	else{
		check->qty += qty;
	}
	if(add() == 0){
		return 0;
	}
	else{
		return 1;
	}
}

void update(struct Node *bill){
	system("cls");
	int qty;
	do{
		printf("Input new Qty[>=0]: ");
		scanf("%d",&qty);
		getchar();
	}while(qty < 0);
	if(qty == 0){
		if(bill == head){
			head = head->next;
			if(head != NULL) head->prev == NULL;
			free(bill);
		}
		else{
			bill->prev->next = bill->next;
			if(bill->next != NULL) bill->next->prev = bill->prev;
			free(bill);
		}
	}
	else{
		bill->qty = qty;
	}
}

void updateOp(struct Node *bill){
	system("cls");
	char op;
	int qty;
	do{
		printf("Input Operation[-(int) | +(int)]: ");
		scanf(" %c%d",&op,&qty);
		getchar();
	}while(qty < 0 || (op != '-' && op != '+'));
	if(op == '-'){
		bill->qty-=qty;
		if(bill->qty <= 0){
			if(bill == head){
				head = head->next;
				if(head != NULL) head->prev == NULL;
				free(bill);
			}
			else{
				bill->prev->next = bill->next;
				if(bill->next != NULL) bill->next->prev = bill->prev;
				free(bill);
			}
		}
	}
	else{
		bill->qty += qty;
	}
}

void printData(){
	struct Data *temp = database;
	printf("===============================\n");
	printf("| ID | Product       | Price  |\n");
	printf("===============================\n");
	while(temp != NULL){
		printf("| %s | %-13s | %-6d |\n",temp->info.id, temp->info.product, temp->info.price);
		printf("-------------------------------\n");
		temp = temp->next;
	}
	printf("\n");
}

void printBill(){
	struct Node *temp = head;
	if(temp == NULL){
		printf("=============================\n");
		printf("|    Cart Currently Empty   |\n");
		printf("=============================\n");
	}
	else{
		int total = 0;
		printf("<<<<<<<<<<<<<<<<<<<<<<<BILL>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("==================================================\n");
		printf("| ID | Product       | Price  | Qty   | Total    |\n");
		printf("==================================================\n");
		while(temp != NULL){
			int res = temp->info.price*temp->qty;
			total += res;
			printf("| %s | %-13s | %-6d | %-5d | %-8d |\n",temp->info.id, temp->info.product, temp->info.price, temp->qty, res);
			printf("--------------------------------------------------\n");
			temp = temp->next;
		}
		printf("Total: %d$\n",total);	
	}
	printf("\n");
}

void printBye(){
	printf("====================================\n");
	printf("|                                  |\n");
	printf("|          =================       |\n");
	printf("|          | Thank You     |       |\n");
	printf("|          | For Shopping! |       |\n");
	printf("|          =================       |\n");
	printf("|               ____   _           |\n");
	printf("|              /    \\ \\ /          |\n");
	printf("|              |^  ^| //           |\n");
	printf("|              \\____///            |\n");
	printf("|               _||_//             |\n");
	printf("|             //|  |               |\n");
	printf("|            // |  |               |\n");
	printf("|           //  |  |               |\n");
	printf("|          /_\\  |  |               |\n");
	printf("====================================\n");
}

int main()
{
	pushData("A0","Milk Tea",2);
	pushData("A1","Mineral Water",1);
	pushData("A2","RTX 4090",1599);
	pushData("A3","Leng Fan",5);
	pushData("A4","Hash Brown",3);
	printData();
	int opt;
	do{
		system("cls");
		char id[5];
		printData();
		printBill();
		printf("Supermarket Menu\n");
		printf("==========================\n");
		printf("1. Buy\n");
		printf("2. Update\n");
		printf("3. Update Operation\n");
		printf("4. Exit\n");
		scanf("%d",&opt);
		getchar();
		switch(opt){
			case 1:
				system("cls");
				printData();
				int repeat;
				struct Data *search;
				do{
					while(1){
						if(repeat == 1){
							system("cls");
							printData();
						}
						printf("Input Product Id: ");
						scanf("%s",id);
						getchar();
						search = searchData(id);
						if(search == NULL){
							printf("Id Not Found!\n");
						}
						else{
							break;
						}
					}
					repeat = pushBill(search);
				}while(repeat == 1);
				break;
			case 2:
				system("cls");
				printBill();
				if(head == NULL){
					printf("\nPress Enter to Continue . . ."); getchar();
				}
				else{
					while(1){
						struct Node *cart;
						printf("Input Product Id: ");
						scanf("%s",id);
						getchar();
						cart = unique(id);
						if(cart == NULL){
							printf("Product doesn't exist in your cart!\n");
						}
						else{
							update(cart);
							break;
						}
					}
				}
				break;
			case 3:
				system("cls");
				printBill();
				if(head == NULL){
					printf("\nPress Enter to Continue . . ."); getchar();
				}
				else{
					while(1){
						struct Node *cartOp;
						printf("Input Product Id: ");
						scanf("%s",id);
						getchar();
						cartOp = unique(id);
						if(cartOp == NULL){
							printf("Product doesn't exist in your cart!\n");
						}
						else{
							updateOp(cartOp);
							break;
						}
					}
				}
				break;
			case 4:
				system("cls");
				printf("====================================\n");
				printf("|            FINAL CART            |\n");
				printf("====================================\n\n");
				printBill();
				printBye();
				break;
		}
	}while(opt != 4);
	
	
	
 	return 0;
}
