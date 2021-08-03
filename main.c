//1
//  main.c
//  library management
//
//  Created by yassen on 5/6/20.
//  Copyright © 2020 yassen & nouhaila. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const MAX_ADH  = 100 ;
const MAX_BOOK = 100 ;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// address struct :
struct address_t {
    int  ZIP_code;
    char adr_city   [ 20 ] ;
    char adr_street [ 20 ] ;
    int  adr_house ;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//adherent struct :
struct adherent_t {
    int    adr_number ;
    char   adr_lastName  [ 20 ] ;
    char   adr_firstName [ 20 ] ;
    struct address_t address ;
    int    the_number_of_books_borrowed  ;
    };


//author struct :
struct author_t {
    char lastName  [ 20 ] ;
    char firstName [ 20 ] ;
};

//Book struct :
struct book_t {
    int    book_number ;
    char   book_title [ 20 ] ;
    struct author_t author ;
    int    the_numbre_of_borrowing_members ;
};

//to add adherents information
void add_member (struct adherent_t *adhP, struct adherent_t adh [MAX_ADH], int *Numbre_Adherent, int *N_adh){
    
     int answer ;
    //N_adh in order not repeat the ID :
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;

    do {
      adhP = &adh [ *Numbre_Adherent ] ;
         adh [ *Numbre_Adherent ] . adr_number = *N_adh+1000 ;
      
      printf ("\n * Write the last name :  ") ;
      scanf  ("%s", adh [*Numbre_Adherent] .adr_lastName) ;
      printf ("\n * Write the first name : ") ;
      scanf  ("%s" , adh [*Numbre_Adherent] .adr_firstName) ;
      printf ("\n * Enter ZIP code  : ") ;
      scanf  ("%d" , &adh [*Numbre_Adherent] .address.ZIP_code) ;
      printf ("\n * Write the city name : ") ;
      scanf  ("%s" , adh [*Numbre_Adherent] .address.adr_city) ;
      printf ("\n * Enter the name of the street : ") ;
      scanf  ("%s" , adh [*Numbre_Adherent] .address.adr_street) ;
      printf ("\n * Enter the house number : ") ;
      scanf  ("%d" , &adh [*Numbre_Adherent].address.adr_house) ;
      printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
      printf ("\n * Do you want to add another adherent ?\n * if  Yes type (1), if not No (2) : ") ;
      scanf  ("%d" ,&answer) ;
      printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
      
      if ( answer != 1 && answer != 2 ) {
    
        do {
            printf ("\n * Type 1 or 2 \n * For Yes type (1), No (2) : ") ;
            scanf  ("%d" ,&answer ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        } while    ( answer != 1 && answer != 1 ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }

    adh [*Numbre_Adherent].the_number_of_books_borrowed = 0 ;
    *Numbre_Adherent = *Numbre_Adherent+1 ;
    *N_adh = *N_adh + 1;
   
    } while ( answer == 1) ;
    
    adhP = adh ;
    
}
   void remove_adh (struct adherent_t adh[MAX_ADH], struct adherent_t *adhP, int *Numbre_Adherent){
    int i , j , N = 0 ;
    int answer ;
    char Name [ 30 ] ;
    int ID ;
    
    do {
    
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
         printf ("\n * What is the name you want to delete ? : ") ;
        scanf  ("%s" , Name ) ;
        printf ("\n * Type her ID  : ") ;
        scanf  ("%d" , &ID ) ;
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
    for ( i = 0; i < *Numbre_Adherent ; i++ ) {
    
        if ( strcmp ( Name , adh [ i ] .adr_lastName ) == 0 && ID == adh [ i ].adr_number ) {
            N = 1 ;
                for ( j = i ; j < *Numbre_Adherent + 1 ; j++ )
                    adh [ j ] = adh [ j + 1 ] ;
            
            printf ("\n * adherent has been deleted\n") ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
            *Numbre_Adherent = *Numbre_Adherent - 1;  //to lose one after delete
        }
         
        }
        if ( N == 0 ) {
        printf ("\n We’re sorry, nobody has this name or ID \n") ;
         printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        }
        
        printf ("\n * Do you want to delete another adherent ? \n> for Yes type (1) , No (2) ==> ") ;
        scanf ("%d" ,&answer ) ;
        
        if ( answer != 1 && answer != 2 ) {
    
            do {
                printf ("\n * Type 1 or 2 \n For Yes type(1), No(2) : ") ;
                scanf  ("%d" ,&answer ) ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
            
            } while    ( answer != 1 && answer != 2 ) ;
            printf     ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        }
    
        } while ( answer == 1 ) ;
        
    adhP = adh ;
    
    }
    //allows user to edit adherent information
    void edit_Adherent ( struct adherent_t adh [MAX_ADH] , struct adherent_t *adhP , int *Numbre_Adherent) {
    
    int i , choice  , edit , N ;
    char lastname [ 30 ] , firstname [ 30 ] ;
    // ask the user if another adherent wants to change something or finish
    
    do {
    
    printf ("\n * Give the adherent name you want to change : ") ;
    scanf  ("%s" , lastname) ;

    printf ("\n * Give his first name : ") ;
    scanf  ("%s" , firstname ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    N = 0 ;
    
    for ( i = 0 ; i < *Numbre_Adherent ; i++ ) {

        if ( strcmp ( lastname , adh[ i ].adr_lastName ) == 0 && strcmp ( firstname , adh[ i ].adr_firstName ) ==0 ) {
        N = 1 ;
    //ask the user if he wants to change another choice for this member
             do {
        
             printf ("\n * Do you want to change something else \n") ;
              printf (" * (1)for lastname \n * (2)for firstname \n * (3)for ZIP code \n") ;
             printf (" * (4)for the name of the city \n * (5)for the street name \n * (6)for house number\n * your choice ==> ") ;
             scanf  ("%d" , &choice ) ;
             printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
            
                switch ( choice ) {

                case 1 :
                 printf ("\n * Write the new lastname  : ") ;
                scanf  ("%s" , adh [ i ] .adr_lastName ) ;
                 printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                break ;

                case 2 :
                printf ("\n * Write the new firstname  : ") ;
                scanf  ("%s" , adh [ i ] .adr_firstName ) ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                break ;

                case 3 :
                printf ("\n * Write the new ZIP code  : ") ;
                scanf  ("%d",&adh[i].address.ZIP_code) ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                break ;
                
                case 4 :
                printf ("\n * Write the new name of the city : ") ;
                scanf  ("%s" , adh [ i ] .address.adr_city ) ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                break ;
                
                case 5 :
                printf ("\n * write the new name of the street : ") ;
                scanf  ("%s" , adh [ i ] .address.adr_street ) ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                break ;
             
                case 6 :
                 printf ("\n * Write the new house number : ") ;
                scanf  ("%d" , &adh [ i ] .address.adr_house ) ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                break ;
        
                default : printf ("\n * Write a number between 1-6 *\n") ;
                }
                
    printf ("\n * Do you want to change something else ?\n\n * for Yes type (1) , No type (2) : ") ;
    scanf  ("%d" ,&edit ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;

    if ( edit != 1 && edit != 2 ) {
    
        do {
            printf ("\n * Type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
            scanf  ("%d" ,&edit ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        } while    ( edit != 1 && edit != 2 ) ;
    
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
    
        } while ( edit == 1 ) ;
    }
    }
    
    
    if ( N == 0 ) {
    printf ("\n *There is no one with that name* \n") ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }

    printf ("\n * Do you want to edit other adherent ?\n * for Yes Type(1) , No(2) : ") ;
    scanf  ("%d" ,&edit ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
    if ( edit != 1 && edit != 2 ) {
  
        do {
            printf ("\n * Type 1 or 2 \n\n * For Yes type(1), No(2) : ") ;
            scanf  ("%d" ,&edit ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
           } while ( edit != 1 && edit != 2 ) ;
    
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
    
    } while ( edit == 1 ) ;
    
    adhP = adh ;
}
//fonction to display the list of adherents in alphabetical order
void  display_list_of_adherent_in_alphabetical_order ( struct adherent_t adh[MAX_ADH], int *Numbre_Adherent ){
    
    int i = 0 , j , test ;
    struct adherent_t temp ;
    
    do {
        test = 0;
    
        for ( j = *Numbre_Adherent - 1 ; j > i ; j-- ) {
        
            if ( strcmp ( adh [ j ] .adr_lastName , adh [ j - 1 ] .adr_lastName ) < 0 ) {
                temp = adh [ j ] ;
                adh [ j ] = adh [ j - 1 ] ;
                adh [ j - 1 ] = temp ;
                test = 1 ;
            }
        }
        i++;
    } while ( test == 1 && i < *Numbre_Adherent ) ;
    
    for ( i = 0 ; i < *Numbre_Adherent ; i++) {
    printf ("\n>> %s %s \n\n" , adh [ i ] .adr_lastName , adh [ i ] .adr_firstName ) ;
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}


//to find a adherent
void find_a_adherent ( struct adherent_t adh[MAX_ADH] , int *Numbre_Adherent){

    int i , N = 0 , answer ;
    char find_lastname [ 30 ] ;
    char find_firstname [ 30 ] ;

    do {
    
    printf (" * Write the last name : ") ;
    scanf  ("%s", find_lastname ) ;
    
    printf (" * Write the first name : ") ;
    scanf  ("%s", find_firstname);
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    for(i = 0 ; i < *Numbre_Adherent; i++){
    
        if ( strcmp ( find_lastname , adh [ i ] .adr_lastName ) == 0 && strcmp ( find_firstname , adh [ i ] .adr_firstName ) ==0 ) {
            //if the data true
            N = 1 ;
           printf (" * %s %s 's information :\n\n" , adh [ i ] .adr_lastName , adh [ i ] .adr_firstName ) ;
            printf ("\n : ID : %d" , adh [ i ] .adr_number ) ;
           printf ("\n : last name : %s" , adh [ i ] .adr_lastName ) ;
           printf ("\n : First name : %s" , adh [ i ] .adr_firstName ) ;
           printf ("\n : ZIP code : %d" , adh [ i ] .address.ZIP_code ) ;
           printf ("\n : Name of the city : %s" , adh [ i ] . address .adr_city ) ;
           printf ("\n : Name of the street : %s" , adh [ i ] . address .adr_street ) ;
           printf ("\n : House number  : %d\n" , adh [ i ] . address .adr_house ) ;
           printf ("\n : The number of books borrowed  : %d" , adh [ i ] .the_number_of_books_borrowed ) ;
           printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
        }
        
    }
    // if the data not true
    if ( N == 0 ) {
        printf ("\n * There is no one with that name *\n") ;
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
        
    printf ("\n * Do you want to find another adherent ?\n\n * for Yes type(1) , No(2) : ") ;
    scanf ("%d" ,&answer ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
    if ( answer != 1 && answer != 2) {

        do {
            printf ("\n * Type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
            scanf  ("%d" , &answer ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
            
        } while ( answer != 1 && answer != 2) ;
        
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
    
    } while ( answer == 1) ;
}
// 2. to add book information
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//to register new books
void add_book ( struct book_t *bookP , struct book_t book [MAX_BOOK] , int *Numbre_book , int *N_book) {
    
    int answer ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
     
    do {
    bookP = &book [ *Numbre_book ] ;
       book [ *Numbre_book ] .book_number = *N_book + 1000 ;
    printf ("\n * Write the book title : ") ;
    scanf  ("%s" , book [ *Numbre_book ] .book_title ) ;
    printf ("\n * Write the last name of the author : ") ;
    scanf  ("%s" , book [ *Numbre_book ] .author.lastName ) ;
    printf ("\n * Write the first name of the author : ") ;
    scanf  ("%s" , book [ *Numbre_book ] . author.firstName ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
 //if wanting to add another book
    printf ("\n * Do you want to add another book?\n\n * for Yes type(1), No(2) : ") ;
    scanf  ("%d" ,&answer ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
    if ( answer != 1 && answer != 2 ) {
        
        do {
            printf ("\n * Type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
            scanf  ("%d" ,&answer ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        } while ( answer != 1 && answer != 2 ) ;

    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
    
    book [ *Numbre_book ] .the_numbre_of_borrowing_members  = 0 ;
    *Numbre_book = *Numbre_book + 1 ;
    *N_book = *N_book + 1 ;
    
    } while ( answer == 1 ) ;
    
    bookP = book ;
    }
    //to delete a book
void delete_book ( struct book_t book [MAX_BOOK] , struct book_t *bookP , int *Numbre_book ) {
 
    int i , j , N = 0 ;
    int answer ;
    char Title [ 30 ] ;
    int ID ;
    
    do {
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    printf ("\n * What is the title of the book you want to delete ?  ") ;
    scanf ("%s" , Title ) ;
    printf ("\n * Give his id : ") ;
    scanf ("%d" , &ID ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    //if the data true
    for ( i = 0 ; i < *Numbre_book ; i++ ) {
        
        if ( strcmp ( Title , book [ i ] .book_title ) == 0 && ID == book [ i ] .book_number ) {
            N = 1 ;
            for ( j = i ; j < *Numbre_book+1 ; j++ )
                 book [ j ]  = book [ j + 1 ] ;
            
            printf ("\n * The book has been deleted \n") ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
            *Numbre_book = *Numbre_book - 1 ;  //to lose one after delete
        }
    }
    //if the data not true
        if ( N == 0 ) {
        printf ("\n *There is no book with this title or ID*\n") ;
         printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        }
        //to ask the user if want to delete another member
        printf ("\n *Do you want to delete another book ?\n\n * for Yes type(1) , No(2) : ") ;
        scanf  ("%d" , &answer ) ;
        
        if ( answer != 1 && answer != 2 ) {
        
            do {
               printf ("\n * Type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
               scanf  ("%d" ,&answer ) ;
               printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
            } while ( answer != 1 && answer != 2 ) ;
            
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        }
        
        } while ( answer == 1 ) ;
        
    bookP = book;
}
    //to edit a book
   //we have a problem here , we can't modify the second book
void edit_book ( struct book_t book [MAX_BOOK] , struct book_t *bookP , int *Numbre_book ) {
    
    int i , choice , edit , ID , N ;
    char Title [ 30 ] ;
    do {
    printf ("\n * Give the title of the book you want to change : ") ;
    scanf ("%s" , Title ) ;
    
    printf ("\n * Give his ID : ") ;
    scanf ("%d" , &ID ) ;
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    N = 0 ;
    
    for ( i = 0 ; i < *Numbre_book ; i++ ) {
        
          if ( strcmp ( Title , book [ i ] .book_title ) ==0 && ID == book [ i ]  .book_number ) {
              //if data true
       N = 1 ;
    //this loop to ask the user if want to change anything else in this book
           do {
        
           printf ("\n * What do you want to change?\n\n") ;
           printf (" *(1)for Title\n * (2)for author last name \n * (3)for author first name \n\n * your choice : ") ;
           scanf ("%d" , &choice ) ;
           printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
               
               switch ( choice ) {
               
               case 1 :
               printf ("\n *Write the New title : ") ;
               scanf  ("%s" , book [ i ] .book_title ) ;
               printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
               break ;
               
               case 2 :
               printf ("\n * Write the new last name author : ") ;
               scanf ("%s" , book [ i ] .author.lastName ) ;
               printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                break ;
               
               case 3 :
               printf ("\n * Write the new first name author : ") ;
               scanf ("%s" , book [ i ] .author.firstName ) ;
               printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
               break ;
             
               default : printf ("\n  * Write a number between 1-3 * \n") ;
               }
               
    printf("\n * Do you want to change something else ?\n\n *for Yes type (1) , No type (2) : ");
    scanf ("%d" ,&edit ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
    if ( edit != 1 && edit != 2 ) {
   
        do {
            printf ("\n * Type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
            scanf ("%d" ,&edit ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        } while ( edit != 1 && edit != 2 ) ;
    
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
    
    } while ( edit == 1 ) ;
    }
    }
//if the data not true
    if ( N == 0 ) {
    
    printf ("\n * There is no book with this title * \n") ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
    //if the user wants to modify another book
    printf ("\n * Do you want to change other book ?\n\n * for Yes Type(1) , No(2) : ") ;
    scanf  ("%d" ,&edit ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
    if ( edit != 1 && edit != 2 ) {
    
        do {
            printf ("\n * Type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
            scanf  ("%d" ,&edit ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        } while ( edit != 1 && edit != 2 ) ;
        
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
    
    } while ( edit == 1 ) ;
    
    bookP = book ;
}
    //to display the list of books in alphabetical order
void  Display_the_Book_list_in_alphabetical_order ( struct book_t book [MAX_BOOK] , int *Numbre_book ) {

    int i = 0 , j , test ;
    struct book_t temp ;
    
    do{
        test = 0;
        
        for( j = *Numbre_book - 1 ; j > i ; j-- ) {
        
            if ( strcmp ( book [ j ] .book_title , book [ j - 1 ] .book_title ) < 0) {
                temp = book [ j ] ;
                book [ j ]  = book [ j - 1  ] ;
                book [ j -  1 ] = temp ;
                test = 1 ;
            }
        }
        i++ ;
    } while ( test == 1 && i < *Numbre_book ) ;
    
for ( i = 0 ; i < *Numbre_book ; i++ ) {
    printf ("\n * %s \n\n" , book [ i ] .book_title ) ;
}
    
}
//to find a book
void find_a_book ( struct book_t book [MAX_BOOK] , int *Numbre_book ) {
    
    int i , N = 0  , answer ;
    char find_Title [ 30 ] ;
    int ID ;

    do {
    
        printf ("* Write the title : ") ;
        scanf ("%s" , find_Title) ;
        printf ("* Write his ID : ") ;
        scanf ("%d" , &ID ) ;
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        
        for ( i = 0 ; i < *Numbre_book ; i++ ) {
        
             if ( strcmp ( find_Title , book [ i ] .book_title ) == 0 && ID == book [ i ] .book_number ) {
                 N = 1 ;
                 printf ("* Book information %s :\n\n" , book [ i ] .book_title ) ;
                  printf ("\n : ID : %d" , book [ i ] .book_number ) ;
                 printf ("\n : Title : %s" , book [ i ].book_title ) ;
                 printf ("\n : Author last name : %s" , book [ i  ] .author.lastName ) ;
                 printf ("\n : Author first name : %s" , book [ i ] .author.firstName ) ;
                 printf ("\n : ID of borrowing adherent : %d" , book [ i ].the_numbre_of_borrowing_members ) ;
                 printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                 break;
             }
        }
    //if the data not true
    if ( N == 0 ) {
    printf ("\n * There is no book with this title or ID * \n") ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
        
    printf ("\n* Do you want to search for another book?\n\n * for Yes type(1) , No(2) : ") ;
    scanf  ("%d" ,&answer ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
    if ( answer != 1 && answer != 2 ) {
        
        do {
            printf ("\n * 0type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
            scanf  ("%d" ,&answer ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        } while ( answer != 1 && answer != 2 ) ;
        
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
    
    } while ( answer == 1 ) ;
}

// 3.for borrowing
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void to_borrow_a_book ( struct adherent_t *adhP, struct adherent_t adh[MAX_ADH], int *Numbre_Adherent, struct book_t *bookP, struct book_t book[MAX_BOOK], int *Numbre_book){
    int N1 , N2 , N3 ;
    int ID , answer_adh , answer_book , i , j ;
    char Title [ 30 ] ;
    
    do {
    
    printf ("\n * Who is a member who wishes to borrow 'Type their ID' : ") ;
    scanf ("%d" , &ID ) ;
    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
    N1 = 0 ;
    
        for ( i = 0 ; i < *Numbre_Adherent ; i++ ) {
            if ( ID == ( adh [ i ] .adr_number ) ) {
            N1 = 1 ;
        
            do {
                printf ("\n\n * What is the book wants %s %s 'Type Book title' : " , adh [ i ] .adr_lastName , adh [ i ] .adr_firstName ) ;
                scanf ("%s" , Title ) ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                
                N2 = 0 ;
                N3 = 0 ;
                
                for( j = 0 ; j < *Numbre_book ; j++) {
            
                     if ( strcmp ( Title , book [ j ] .book_title ) == 0 && book [ j ] .the_numbre_of_borrowing_members == 0 ) {
            //if the data true
                        N2 = 1 ;
                        printf ("\n * Operation successfully completed *") ;
                        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                        
                        book [ j ] . the_numbre_of_borrowing_members = adh [ i ] .adr_number ;
                        adh [ i ] . the_number_of_books_borrowed = ( adh [ i ] . the_number_of_books_borrowed ) + 1 ;
                        break ;
                    }
        
                    if ( strcmp ( Title , book [ j ] .book_title ) == 0 && book [ j ] . the_numbre_of_borrowing_members != 0 ) {
                     N3 = N3 + 1 ;
                    N2 = 1 ;
                    }
    
                }
          //if data not true
                if ( N2 == 0 ) {
                 printf ("\n* There is no book with this title *\n") ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                }
        //if the book already borrowed
                if ( N3 != 0 ) {
                printf ("\n* This book is not available because it is already Borrowed\n") ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                }
        
                printf ("\n* Do you want to borrow another book?\n\n* for Yes  Type(1), No(2) : ") ;
                scanf  ("%d" ,&answer_book ) ;
                printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        
                if ( answer_book != 1 && answer_book != 2 ) {
                    
                    do {
                       printf ("\n *  Type 1 or 2 \n\n * for Yes type(1), No(2) ==> ") ;
                       scanf ("%d" ,&answer_book ) ;
                       printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                    } while ( answer_book != 1 && answer_book != 2 ) ;
                    
                    printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                }
    
            } while ( answer_book == 1 ) ;
            }
        }
        //if the false adherent data
    if ( N1 == 0 ) {
        printf ("\n * There is no one with this name or ID *\n") ;
    }
    
    printf ("\n * Is there anyone else who wants to borrow a book ? \n\n * for Yes Type(1), No(2) : ") ;
    scanf ("%d" ,&answer_adh ) ;
    
    if ( answer_adh != 1 && answer_adh != 2 ) {
        
        do {
            printf ("\n * Type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
            scanf ("%d",&answer_adh ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        } while ( answer_adh != 1 && answer_adh != 2 ) ;
        
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    }
    
    } while ( answer_adh == 1 ) ;
    
    adhP = adh ;
    bookP = book ;
}
//to display the list of borrowers
void display_the_list_of_borrowers(struct book_t book[MAX_BOOK] , int *Numbre_book , struct adherent_t adh[MAX_ADH] , int *Numbre_Adherent){
    
    int i , j ;
    printf ("\n * The borrowing book is :\n\n") ;
    
    for ( i = 0 ; i < *Numbre_book ; i++ ) {
    
        if ( book [ i ] . the_numbre_of_borrowing_members != 0 ) {
            
            for ( j = 0 ; j < *Numbre_Adherent ; j++ ) {
        
                if ( book [ i ] . the_numbre_of_borrowing_members == adh [ j ] .adr_number ) {
                    printf (" * %s  ( %s %s the borrower is %d' )\n\n" , book [ i ] .book_title , adh [ j ] .adr_lastName , adh [ j ] .adr_firstName , adh [ j ] .adr_number ) ;
                }
            }
            
        }
    }
    
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
//to return a book
void return_a_book( struct adherent_t *adhP, struct adherent_t adh[MAX_ADH], int *Numbre_Adherent, struct book_t *bookP, struct book_t book[MAX_BOOK], int *Numbre_book){

    int N1 , N2 , N3 , i , j , answer_return , answer_adh , ID ;
    char name [ 30 ] , Title [ 30 ] ;
    
    do {
        //if the data true
       N1 = 0 ;
       printf ("\n * Who is the member who will return the book : ") ;
       scanf  ("%s" , name) ;
       printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
       printf ("\n* Write his ID : ") ;
       scanf  ("%d" , &ID ) ;
       printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
       
       for ( i = 0 ; i < *Numbre_Adherent ; i++ ) {
           
           if ( strcmp ( name , adh [ i ] .adr_lastName ) == 0 && ID == adh [ i ] .adr_number ) {
               N1 = 1 ; //if find the adherent N=1
               do {
                  N2 = 0 ;
                  N3 = 0 ;
                  
                  printf ("\n * What is the book you want to return : ") ;
                     scanf ("%s" , Title ) ;
                  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                   
                   for ( j = 0 ; j < *Numbre_book ; j++ ) {
                   
                      if ( strcmp ( Title , book [ j ] .book_title ) == 0 && book [ j ] .the_numbre_of_borrowing_members  == adh [ i ] .adr_number ) {
                          N3 = 1 ; //if find the book with the adherent id
                          printf ("\n * Operation successfully completed ") ;
                          
                          adh [ i ] . the_number_of_books_borrowed - 1 ;
                          book [ j ] . the_numbre_of_borrowing_members = 0 ;
                      }
        
                      if ( strcmp ( Title ,book [ j ] . book_title ) == 0 && book [ j ] . the_numbre_of_borrowing_members != adh [ i ] . adr_number ) {
                      N2 = 1 ; //if find the book with different id
                      }
                   }
                   
                   if ( N2 == 1 && N3 == 0 ) {
                       printf ("\n *You are not the one who took this book *\n") ;
                   }
    
                   if ( N2 == 0 && N3 == 0 ) {
                       printf ("\n * There is no book with this title *\n") ;
                          printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                    }
    
                   printf ("\n * Do you want to return another book ?\n\n * for Yes type(1) , No(2) ==> ") ;
                   scanf  ("%d" ,&answer_return ) ;
                   printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
                   if ( answer_return != 1 && answer_return != 2 ) {
                      do {
                         printf ("\n * Type 1 or 2 \n\n *for Yes type(1), No(2) : ") ;
                         scanf  ("%d" ,&answer_return ) ;
                         printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                      } while ( answer_return != 1 && answer_return != 2 ) ;
                      
                      printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                   }
    
                } while ( answer_return == 1 ) ;
            }
         }
         
         if ( N1 == 0 ) {
            printf ("\n * We have no member with this name * \n") ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        }
    
        printf ("\n * Is there another person who is going to return a book?\n\n * for Yes type(1) , No(2) : ") ;
        scanf  ("%d" ,&answer_adh ) ;
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
    
        if ( answer_adh != 1 && answer_adh != 2 ) {
           
           do {
               printf ("\n * Type 1 or 2 \n\n * for Yes type(1), No(2) : ") ;
               scanf ( "%d" ,&answer_adh ) ;
               printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
           } while ( answer_adh != 1 && answer_adh != 2 ) ;
    
           printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
        }
    
        } while ( answer_adh == 1 ) ;
    
    adhP = adh ;
    bookP = book ;
}

//to display the borrower list
void Display_the_borrower_list ( struct adherent_t adh [MAX_ADH] , int *Numbre_Adherent ) {
    
    int i ;

    printf ("\n * The list of book borrowers :\n") ;
    
    for ( i = 0 ; i < *Numbre_Adherent ; i++ ) {
        
        if ( adh [ i ] .the_number_of_books_borrowed > 0 ) {
            printf ("\n * %s %s  ( has %d this book ) \n\n" , adh [ i ] .adr_lastName , adh [ i ] .adr_firstName , adh [ i ] .the_number_of_books_borrowed ) ;
        }
    }
    
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
struct adherent_t adh[MAX_ADH];
struct book_t book[MAX_BOOK];
struct adherent_t *adhPTR;
int answer;
int choice , choice_adh_management , choice_add_ed_de_adh, choice_book_management , choice_add_ed_de_book , choice_bor ;
int N_adh=0;
int N_book=0;
int Numbre_Adherent = 0;
int Numbre_book = 0 ;
char find_name[30];
struct adherent_t *adhP = adh;
struct book_t *bookP = book;

    
 do {
   printf ("\t\t       .--.           .---.        .-.\n");
   printf ("\t\t    .--|--|   .-.     | A |  .---. |~|    .--.\n");
   printf ("\t\t.--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---.\n");
   printf ("\t\t|§§|NT2|oc|===| |~~|§§| C |--|   |_|~|CATS|  |___|-.\n");
   printf ("\t\t|  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|\n");
   printf ("\t\t|  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |\n");
   printf ("\t\t|~~|===|--|===|~|~~|§§|~~~|--|:::|=|~|----|==|---|=|\n");
   printf ("\t\t^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'\n");
   printf ("\t\t ~~~~~~~~~~~~~ Main menu ~~~~~~~~~~~~~\n\n") ;
   printf ("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
   printf ("\t\t~                                            ~\n") ;
   puts   ("\t\t~  For adherent management    => Type (1)    ~ ") ;
   puts   ("\t\t~  For book management        => Type (2)    ~ ") ;
   puts   ("\t\t~  For borrows management     => type (3)    ~") ;
   puts   ("\t\t~  To exit the program        => type (4)    ~") ;
   printf ("\t\t~                                            ~\n") ;
   printf ("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
   
   printf ("\n ~ Type your choice : ") ;
   scanf ("%d" , &choice ) ;
   printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
       
   switch ( choice ) {
        
        case 1 :
         
          do {
           printf ("\t\t       .--.           .---.        .-.\n");
           printf ("\t\t    .--|--|   .-.     | A |  .---. |~|    .--.\n");
           printf ("\t\t.--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---.\n");
           printf ("\t\t|§§|NT2|oc|===| |~~|§§| C |--|   |_|~|CATS|  |___|-.\n");
           printf ("\t\t|  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|\n");
           printf ("\t\t|  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |\n");
           printf ("\t\t|~~|===|--|===|~|~~|§§|~~~|--|:::|=|~|----|==|---|=|\n");
           printf ("\t\t^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'\n");
         
            printf("\n\n\t\t  §§§§§§§§§§ Borrowing Management §§§§§§§§§§\n\n\n") ;
   
            printf ("§§ For Add, Edit, Remove                                => type (1)\n\n") ;
            printf ("§§ To Display the list of members in alphabetical order => type (2)\n\n") ;
            printf ("§§ To find and display a member                         => type (3)\n\n") ;
            printf ("§§ To Return to the main menu                           => type (4)\n\n") ;
  
            printf ("\nTapez votre choix => ") ;
            scanf ("%d" , &choice_adh_management ) ;
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
 
              switch ( choice_adh_management ) {
 
                   case 1 :
                     
                   do {
                   
                       printf ("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                      printf ("\t\t~                                ~\n") ;
                      puts ("\t\t~  For add    => type (1)  ~") ;
                      puts ("\t\t~  For edit   => type (2)  ~") ;
                      puts ("\t\t~  For remove => type (3)  ~") ;
                      puts ("\t\t~  For Return => type (4)  ~") ;
                      printf ("\t\t~                                ~\n") ;
                      printf ("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                      printf ("\n Type your choice => ") ;
                      scanf ("%d" , &choice_add_ed_de_adh ) ;
    
                      switch ( choice_add_ed_de_adh ) {
                        
                        case 1 :
                          
                          add_member ( adhP , &adh , &Numbre_Adherent , &N_adh ) ;
                        
                        break ;
            
                        case 2 :
                         
                          edit_Adherent ( &adh , adhP , &Numbre_Adherent ) ;
                        
                        break ;
            
                        case 3 :
            
                          remove_adh ( &adh , adhP , &Numbre_Adherent ) ;
            
                        break ;
            
                        case 4 :
                        break;
            
                        default : printf ("\n §§§§§§§§§§\n ~ type enter 1-4 ~ \n §§§§§§§§§§\n") ;
            
                      }
                      } while ( choice_add_ed_de_adh != 4 ) ;
    
                   break;
 
                   case 2 :
                    
                     display_list_of_adherent_in_alphabetical_order ( &adh , &Numbre_Adherent ) ;
               
                break ;
 
                   case 3 :
               
                find_a_adherent ( &adh , &Numbre_Adherent ) ;
               
                break ;
 
                 case 4 :
                break;
               
                default : printf ("\n §§§§§§§§§§\n ~ type enter 1-4 ~ \n §§§§§§§§§§\n") ;
              
              }
          }while ( choice_adh_management != 4);
        
        break;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2 :
        
           do {
                 printf ("\t\t       .--.           .---.        .-.\n");
              printf ("\t\t    .--|--|   .-.     | A |  .---. |~|    .--.\n");
              printf ("\t\t.--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---.\n");
              printf ("\t\t|§§|NT2|oc|===| |~~|§§| C |--|   |_|~|CATS|  |___|-.\n");
              printf ("\t\t|  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|\n");
              printf ("\t\t|  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |\n");
              printf ("\t\t|~~|===|--|===|~|~~|§§|~~~|--|:::|=|~|----|==|---|=|\n");
              printf ("\t\t^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'\n");
              printf ("\n\n\t\t  §§§§§§§§§§ Book Management §§§§§§§§§§\n\n\n") ;
   
              printf ("§§ For Add, Edit, Remove                                                => type (1)\n\n") ;
              printf ("§§ To Display the list of books in alphabetical order                   => type (2)\n\n") ;
              printf ("§§ Search for a book by title and display the corresponding information => type (3)\n\n") ;
              printf ("§§ To Return to the main menu                                           => type (4)\n\n") ;
 
              printf ("\n Type your choice  => ") ;
              scanf ("%d" , &choice_book_management ) ;
              printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
            
            switch ( choice_book_management ) {
 
                  case 1 :
                     
                   do {
                      printf ("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                      printf ("\t\t~                                ~\n") ;
                      puts ("\t\t~  For Add    => type (1)  ~") ;
                      puts ("\t\t~  For Edit   => type (2)  ~") ;
                      puts ("\t\t~  For remove => type (3)  ~") ;
                      puts ("\t\t~  For return => type (4)  ~") ;
                      printf ("\t\t~                                ~\n") ;
                      printf ("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n") ;
                      
                      printf ("\n Type your choice  => ") ;
                      scanf ("%d" , &choice_add_ed_de_book ) ;
    
                      switch ( choice_add_ed_de_book ) {
            
                         case 1 :
                             
                         add_book ( bookP , &book , &Numbre_book , &N_book ) ;
                         break ;
            
                         case 2 :
                          edit_book(&book,bookP,&Numbre_book);
                         break;
            
            case 3 :
            delete_book (&book,bookP,&Numbre_book);
            break;
            
            case 4 :
            break;
            
            default : printf("\n §§§§§§§§§§\n ~ type enter 1-4 ~\n §§§§§§§§§§ \n");
    }
    }while( choice_add_ed_de_book != 4);
    
            
        break;
        
        case 2 :
        Display_the_Book_list_in_alphabetical_order (&book, &Numbre_book );
        break;
        
        case 3 :
        find_a_book (&book ,&Numbre_book);
        break;
        
        case 4 :
        break;
        
        default : printf("\n §§§§§§§§§§ \n ~ Type enter 1-4 ~ \n §§§§§§§§§§ \n");
        
        }
        }while(choice_add_ed_de_book != 4);
        break;
        
        case 3 :
            
            do{
    printf ("\t\t       .--.           .---.        .-.\n");
    printf ("\t\t    .--|--|   .-.     | A |  .---. |~|    .--.\n");
    printf ("\t\t.--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---.\n");
    printf ("\t\t|§§|NT2|oc|===| |~~|§§| C |--|   |_|~|CATS|  |___|-.\n");
    printf ("\t\t|  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|\n");
    printf ("\t\t|  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |\n");
    printf ("\t\t|~~|===|--|===|~|~~|§§|~~~|--|:::|=|~|----|==|---|=|\n");
    printf ("\t\t^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'\n");
            
    printf("\n\n\t\t  §§§§§§§§§§ Borrowing Management §§§§§§§§§§ \n\n\n");
   
   printf("§§ To borrow a book                             => type (1)\n\n");
   printf("§§ To display the list of borrowed books        => type (2)\n\n");
   printf("§§ To return a book                             => type (3)\n\n");
   printf("§§ To view the list of book borrowers           => type (4)\n\n");
   printf("§§ To return to main menu                       => type (5)\n\n");
   printf("\n Type your choice   => ");
   scanf("%d",&choice_bor);
   printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   
   switch ( choice_bor ){
       
           case 1 :
           to_borrow_a_book (adhP,&adh,&Numbre_Adherent,bookP,&book,&Numbre_book);
           break;
           
           case 2 :
           display_the_list_of_borrowers(&book ,&Numbre_book ,&adh , &Numbre_Adherent);
           break;
           
           case 3 :
           return_a_book(adhP,&adh,&Numbre_Adherent,bookP,&book,&Numbre_book);
           break;
           
           case 4 :
           Display_the_borrower_list (&adh, &Numbre_Adherent);
           break;
           
           case 5 :
           break;
           
           default : printf("\n §§§§§§§§§§ \n ~ type enter  1-5 ~ \n §§§§§§§§§§ \n");
           
           
           }
          
   }while( choice_bor != 5);
   
        break;
        
        case 4 :
        printf("\n\n thank you !!");
        
        break;
        
        default : printf("\n §§§§§§§§§§ \n ~ type enter 1-4 ~ \n §§§§§§§§§§ \n");
            
    }
    
    }while(choice != 4);


    
    return 0;
}
