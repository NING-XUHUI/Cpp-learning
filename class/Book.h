//
// Created by 宁旭晖 on 2019/12/28.
//

#ifndef CLASS_BOOK_H
#define CLASS_BOOK_H

class Book {
private:
    char bookName;
    char bookId;
    char bookWriter;
    int  bookPrice;
public:
    Book(){
        bookName = ' ';
        bookId = ' ';
        bookWriter = ' ';
        bookPrice = 0;
    }
    Book(char name,char id,char writer,int price){
        bookPrice = price;
        bookId = id;
        bookName = name;
        bookWriter = writer;
    }

    void bookPrint();

};


#endif //CLASS_BOOK_H
