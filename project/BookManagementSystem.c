#include <stdio.h>
#include <string.h>
#define size 100
typedef struct BookManagementSystem
{
  int bookID;
  char bookName[50];
  char authorName[50];
  char category[20];
  float price;
  int rating;
} Book;

void addBook(Book *, int *);
void removeBook(Book[], int *);
void searchByID(Book[], int);
void searchByName(Book[], int);
void booksByAuthor(Book[], int);
void booksByCategory(Book[], int);
void updateBook(Book[], int);
void displayAllBooks(Book[], int);
void sortByPrice(Book[], int);
void sortByRating(Book[], int);
void top3Books(Book[], int);

void main()
{
  int choice = -1;
  Book data[size] = {
      {1001, "The Room on the Roof", "Ruskin Bond", "Fiction", 199.0, 5},
      {1002, "Rusty the Boy from the Hills", "Ruskin Bond", "Fiction", 180.0, 4},
      {1003, "The Blue Umbrella", "Ruskin Bond", "Fun/Story", 150.0, 4},
      {1004, "A Face in the Dark", "Ruskin Bond", "Horror", 170.0, 5},
      {1005, "Ghost Stories from the Raj", "Ruskin Bond", "Horror", 210.0, 4},
      {1006, "Train to Pakistan", "Khushwant Singh", "Historical", 250.0, 5},
      {1007, "Malgudi Days", "R. K. Narayan", "Fiction", 200.0, 5},
      {1008, "The Guide", "R. K. Narayan", "Fiction", 220.0, 4},
      {1009, "Swami and Friends", "R. K. Narayan", "Fiction", 180.0, 5},
      {1010, "The Man-Eater of Malgudi", "R. K. Narayan", "Fiction", 190.0, 4},
      {1011, "The White Tiger", "Aravind Adiga", "Satire/Drama", 270.0, 5},
      {1012, "Midnight's Children", "Salman Rushdie", "Fiction", 300.0, 4},
      {1013, "The Palace of Illusions", "Chitra Banerjee Divakaruni", "Mythology", 290.0, 5},
      {1014, "Forest of Enchantments", "Chitra Banerjee Divakaruni", "Mythology", 310.0, 4},
      {1015, "The Last Queen", "Chitra Banerjee Divakaruni", "Historical", 330.0, 4},
      {1016, "Immortals of Meluha", "Amish Tripathi", "Mythological", 250.0, 5},
      {1017, "The Secret of the Nagas", "Amish Tripathi", "Mythological", 260.0, 4},
      {1018, "The Oath of the Vayuputras", "Amish Tripathi", "Mythological", 270.0, 5},
      {1019, "Raavan: Enemy of Aryavarta", "Amish Tripathi", "Mythological", 280.0, 4},
      {1020, "Legend of Suheldev", "Amish Tripathi", "Historical", 290.0, 4},
      {1021, "Pride, Prejudice and Punditry", "Shashi Tharoor", "Non-Fiction", 350.0, 4},
      {1022, "Why I Am a Hindu", "Shashi Tharoor", "Politics/Religion", 320.0, 3},
      {1023, "The Rozabal Line", "Ashwin Sanghi", "Thriller", 240.0, 4},
      {1024, "Chanakya's Chant", "Ashwin Sanghi", "Historical", 260.0, 5},
      {1025, "Keepers of the Kalachakra", "Ashwin Sanghi", "Thriller", 280.0, 4},
      {1026, "The Krishna Key", "Ashwin Sanghi", "Mythology", 270.0, 4},
      {1027, "The Vault of Vishnu", "Ashwin Sanghi", "Thriller", 300.0, 4},
      {1028, "Five Point Someone", "Chetan Bhagat", "Fiction", 200.0, 4},
      {1029, "2 States", "Chetan Bhagat", "Rom-Com", 220.0, 4},
      {1030, "The 3 Mistakes of My Life", "Chetan Bhagat", "Fiction", 210.0, 3},
      {1031, "Half Girlfriend", "Chetan Bhagat", "Rom-Com", 230.0, 3},
      {1032, "One Indian Girl", "Chetan Bhagat", "Fiction", 240.0, 4},
      {1033, "Life’s Amazing Secrets", "Gaur Gopal Das", "Self-help", 250.0, 5},
      {1034, "The Power of Your Subconscious Mind", "Joseph Murphy", "Self-help", 280.0, 5},
      {1035, "Ikigai", "Héctor García", "Philosophy", 300.0, 5},
      {1036, "The Alchemist", "Paulo Coelho", "Fiction", 290.0, 5},
      {1037, "Veronika Decides to Die", "Paulo Coelho", "Fiction", 270.0, 4},
      {1038, "Eleven Minutes", "Paulo Coelho", "Fiction", 260.0, 4},
      {1039, "The Canterville Ghost", "Oscar Wilde", "Horror", 200.0, 4},
      {1040, "Frankenstein", "Mary Shelley", "Horror", 220.0, 5},
      {1041, "Dracula", "Bram Stoker", "Horror", 250.0, 5},
      {1042, "Coraline", "Neil Gaiman", "Horror/Fantasy", 210.0, 5},
      {1043, "The Graveyard Book", "Neil Gaiman", "Fantasy", 230.0, 4},
      {1044, "Goosebumps: Night of the Living Dummy", "R.L. Stine", "Horror", 150.0, 5},
      {1045, "Goosebumps: Say Cheese and Die!", "R.L. Stine", "Horror", 150.0, 4},
      {1046, "Goosebumps: The Haunted Mask", "R.L. Stine", "Horror", 150.0, 4},
      {1047, "Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy", 350.0, 5},
      {1048, "Harry Potter and the Chamber of Secrets", "J.K. Rowling", "Fantasy", 370.0, 5},
      {1049, "Harry Potter and the Prisoner of Azkaban", "J.K. Rowling", "Fantasy", 390.0, 5},
      {1050, "Harry Potter and the Goblet of Fire", "J.K. Rowling", "Fantasy", 410.0, 5}};
  int count = 50;
  while (choice != 0)
  {
    printf("\n**********Book Management System**********\n");
    printf("1.Add new Book\n");
    printf("2.Remove Book\n");
    printf("3.Search Book By Id\n");
    printf("4.Search Book By Name\n");
    printf("5.Show Author's Book\n");
    printf("6.Show Category's Books\n");
    printf("7.Update Book\n");
    printf("8.Display All Books\n");
    printf("9.Sort Books by Price\n");
    printf("10.Sort Books by Rating\n");
    printf("11.Top 3 Books by Rating\n");
    printf("0.exit\n");
    printf("Enter choice\n");
    scanf("%d", &choice);
    fflush(stdin);
    if (choice == 1)
    {
      addBook(data, &count);
    }
    else if (choice == 2)
    {
      removeBook(data, &count);
    }
    else if (choice == 3)
    {
      searchByID(data, count);
    }
    else if (choice == 4)
    {
      searchByName(data, count);
    }
    else if (choice == 5)
    {
      booksByAuthor(data, count);
    }
    else if (choice == 6)
    {
      booksByCategory(data, count);
    }
    else if (choice == 7)
    {
      updateBook(data, count);
    }
    else if (choice == 8)
    {
      displayAllBooks(data, count);
    }
    else if (choice == 9)
    {
      sortByPrice(data, count);
    }
    else if (choice == 10)
    {
      sortByRating(data, count);
    }
    else if (choice == 11)
    {
      top3Books(data, count);
    }
    else if (choice == 0)
    {
      printf("Exiting program.\n");
    }
    else
    {
      printf("Invalid input. Please try again.\n");
    }
  }
}

void addBook(Book *data, int *count)
{
  if (*count >= size)
  {
    printf("Storage is full\n");
    return;
  }
  int id;
  printf("Enter Book ID");
  scanf("%d", &id);
  for (int i = 0; i < *count; i++)
  {
    if (data[i].bookID == id)
    {
      printf("Book ID already in use. Please use a unique ID.\n");
      return;
    }
  }
  data[*count].bookID = id;
  fflush(stdin);
  printf("Enter Book Name: \n");
  scanf(" %[^\n]s", data[*count].bookName);
  fflush(stdin);
  printf("Enter Author Name: \n");
  scanf(" %[^\n]s", data[*count].authorName);
  fflush(stdin);
  printf("Enter Category: \n");
  scanf(" %[^\n]s", data[*count].category);
  fflush(stdin);
  printf("Enter Price: \n");
  scanf("%f", &data[*count].price);
  fflush(stdin);
  printf("Enter Rating (1 to 5): ");
  scanf("%d", &data[*count].rating);
  fflush(stdin);
  (*count)++;
  printf("Book added successfully.\n");
}
void removeBook(Book data[], int *count)
{
  if (*count == 0)
  {
    printf("No books available to remove.\n");
    return;
  }
  int id;
  printf("Enter Book ID to remove:\n");
  scanf("%d", &id);
  int found = 0;
  for (int i = 0; i < *count; i++)
  {
    if (data[i].bookID == id)
    {
      for (int j = i; j < *count - 1; j++)
      {
        data[j] = data[j + 1];
      }
      (*count)--;
      found = 1;
      printf("Book with ID %d removed successfully.\n", id);
      break;
    }
  }
  if (!found)
  {
    printf("Book with ID %d not found.\n", id);
  }
}
void searchByID(Book data[], int count)
{
  if (count == 0)
  {
    printf("No books available.\n");
    return;
  }
  int id;
  printf("Enter Book ID to search:\n");
  scanf("%d", &id);
  int found = 0;
  for (int i = 0; i < count; i++)
  {
    if (data[i].bookID == id)
    {
      printf("Book found:\n");
      printf("ID: %d\n", data[i].bookID);
      printf("Name: %s\n", data[i].bookName);
      printf("Author: %s\n", data[i].authorName);
      printf("Category: %s\n", data[i].category);
      printf("Price: %.2f\n", data[i].price);
      printf("Rating: %d\n", data[i].rating);
      found = 1;
      break;
    }
  }
  if (!found)
  {
    printf("Book with ID %d not found.\n", id);
  }
}
void searchByName(Book data[], int count)
{
  if (count == 0)
  {
    printf("No books available.\n");
    return;
  }
  char name[50];
  printf("Enter Book Name to search:\n");
  fflush(stdin);
  scanf("%[^\n]s", name);
  int found = 0;
  for (int i = 0; i < count; i++)
  {
    if (strcmp(data[i].bookName, name) == 0)
    {
      printf("Book found:\n");
      printf("ID: %d\n", data[i].bookID);
      printf("Name: %s\n", data[i].bookName);
      printf("Author: %s\n", data[i].authorName);
      printf("Category: %s\n", data[i].category);
      printf("Price: %.2f\n", data[i].price);
      printf("Rating: %d\n", data[i].rating);
      found = 1;
    }
  }
  if (!found)
  {
    printf("No book found with the name \"%s\".\n", name);
  }
}
void booksByAuthor(Book data[], int count)
{
  if (count == 0)
  {
    printf("No books available.\n");
    return;
  }
  char author[50];
  printf("Enter Author Name:\n");
  fflush(stdin);
  scanf("%[^\n]s", author);
  int found = 0;
  printf("\nBooks by %s:\n", author);
  for (int i = 0; i < count; i++)
  {
    if (strcmp(data[i].authorName, author) == 0)
    {
      printf("Book ID: %d\n", data[i].bookID);
      printf("Name: %s\n", data[i].bookName);
      printf("Category: %s\n", data[i].category);
      printf("Price: %.2f\n", data[i].price);
      printf("Rating: %d\n\n", data[i].rating);
      found = 1;
    }
  }
  if (!found)
  {
    printf("No books found by author \"%s\".\n", author);
  }
}
void booksByCategory(Book data[], int count)
{
  if (count == 0)
  {
    printf("No books available.\n");
    return;
  }
  char category[20];
  printf("Enter Category:\n");
  fflush(stdin); // clear input buffer
  scanf("%[^\n]s", category);
  int found = 0;
  printf("\nBooks in category '%s':\n", category);
  for (int i = 0; i < count; i++)
  {
    if (strcmp(data[i].category, category) == 0)
    {
      printf("Book ID: %d\n", data[i].bookID);
      printf("Name: %s\n", data[i].bookName);
      printf("Author: %s\n", data[i].authorName);
      printf("Price: %.2f\n", data[i].price);
      printf("Rating: %d\n\n", data[i].rating);
      found = 1;
    }
  }
  if (!found)
  {
    printf("No books found in category \"%s\".\n", category);
  }
}
void updateBook(Book data[], int count)
{
  if (count == 0)
  {
    printf("No books available to update.\n");
    return;
  }
  int id, found = 0;
  printf("Enter Book ID to update:\n");
  scanf("%d", &id);
  for (int i = 0; i < count; i++)
  {
    if (data[i].bookID == id)
    {
      printf("Book found. Enter new details:\n");
      printf("Enter new Book ID:\n");
      scanf("%d", &data[i].bookID);
      fflush(stdin);
      printf("Enter new Book Name:\n");
      scanf(" %[^\n]s", data[i].bookName);
      fflush(stdin);
      printf("Enter new Author Name:\n");
      scanf(" %[^\n]s", data[i].authorName);
      fflush(stdin);
      printf("Enter new Category:\n");
      scanf(" %[^\n]s", data[i].category);
      fflush(stdin);
      printf("Enter new Price:\n");
      scanf("%f", &data[i].price);
      fflush(stdin);
      printf("Enter new Rating (1-5):\n");
      scanf("%d", &data[i].rating);
      fflush(stdin);
      printf("Book updated successfully.\n");
      found = 1;
      break;
    }
  }
  if (!found)
  {
    printf("Book with ID %d not found.\n", id);
  }
}
void displayAllBooks(Book data[], int count)
{
  if (count == 0)
  {
    printf("Empty List\n");
    return;
  }
  printf("**********Books List**********\n");
  for (int i = 0; i < count; i++)
  {
    if (data[i].bookID == 0)
      break;
    printf("Book ID         : %d\n", data[i].bookID);
    printf("Book Name       : %s\n", data[i].bookName);
    printf("Author          : %s\n", data[i].authorName);
    printf("Category        : %s\n", data[i].category);
    printf("Price           : %.2f\n", data[i].price);
    printf("Rating (1-5)    : %d\n", data[i].rating);
    printf("***************************\n");
  }
}
void sortByPrice(Book data[], int count)
{
  if (count == 0)
  {
    printf("No books to sort.\n");
    return;
  }
  for (int i = 0; i < count - 1; i++)
  {
    for (int j = 0; j < count - i - 1; j++)
    {
      if (data[j].price > data[j + 1].price)
      {
        Book temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
  printf("Books sorted by Price (Low to High):\n");
  for (int i = 0; i < count; i++)
  {
    printf("ID: %d | Name: %s | Author: %s | Category: %s | Price: %.2f | Rating: %d\n",
           data[i].bookID, data[i].bookName, data[i].authorName, data[i].category,
           data[i].price, data[i].rating);
  }
}
void sortByRating(Book data[], int count)
{
  if (count == 0)
  {
    printf("No books to sort.\n");
    return;
  }
  for (int i = 0; i < count - 1; i++)
  {
    for (int j = 0; j < count - i - 1; j++)
    {
      if (data[j].rating < data[j + 1].rating)
      {
        Book temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
  printf("Books sorted by Rating (High to Low):\n");
  for (int i = 0; i < count; i++)
  {
    printf("ID: %d | Name: %s | Author: %s | Category: %s | Price: %.2f | Rating: %d\n",
           data[i].bookID, data[i].bookName, data[i].authorName, data[i].category,
           data[i].price, data[i].rating);
  }
}
void top3Books(Book data[], int count)
{
  if (count == 0)
  {
    printf("No books available.\n");
    return;
  }
  for (int i = 0; i < count - 1; i++)
  {
    for (int j = 0; j < count - i - 1; j++)
    {
      if (data[j].rating < data[j + 1].rating || (data[j].rating == data[j + 1].rating && data[j].price < data[j + 1].price))
      {
        Book temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
  int limit;
  if (count < 3)
  {
    limit = count;
  }
  else
  {
    limit = 3;
  };
  printf("Top %d Books by Rating:\n", limit);
  for (int i = 0; i < limit; i++)
  {
    printf("ID: %d | Name: %s | Author: %s | Category: %s | Price: %.2f | Rating: %d\n",
           data[i].bookID, data[i].bookName, data[i].authorName, data[i].category,
           data[i].price, data[i].rating);
  }
}