/*最重要三个输出流
 ostream
 ofstream
 ostringstream

 预先定义的输出流对象
 cout：标准输出
 cerr：标准错误输出，没有缓冲，发送给他的内容立即被输出
 clog：类似于cerr，但是有缓冲，缓冲区满时被输出
 */
/*
标准输出换向
  ofstream fout("b.out");
  streambuf* pOld = cout,rdbuf(font.rdbuf());
  //...
  cout.rdbuf(pOld);
*/
/*构造输出流对象
  ofstream类支持磁盘文件输出
  如果在构造函数中指定一个文件名，当构造这个文件时该文件自动打开的
    ofstream myFile("filename");
  可以在调用默认构造函数之后使用open成员函数打开文件
    ofstream myFile;//声明一个静态文件输出流对象
    myFile.open("filename");//打开文件，使流对象与文件建立联系
  在构造对象或用open打开文件时可以指定模式
    ofstream myFile("filename",ios_base::out|ios_base::binary);
*/

/*文件输出流成员函数的三种类型
  与操作符等价的成员函数
  指向非格式化写操作的成员函数
  其他修改流状态且不同于操纵符或插入运算符的成员函数
 */
/*文件输出流成员函数
  open
   把流与一个特定的磁盘文件关联起来
   需要指定打开方式
  put
   把一个字符写到输出流中
  write
   将内存中的一块内容写到一个文件输出流中
  seekp和tellp
   操作文件流的内部指针
  close函数
   关闭与一个文件输出流关联的磁盘文件
  错误处理函数
   在写到一个流时进行错误处理
 */
