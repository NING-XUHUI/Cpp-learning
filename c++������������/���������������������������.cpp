#include <iostream>
#include <thread>

void edit_document_and_display_gui(const std::string& filename){
    open_document_and_display_gui(filename);
    while(!done_editing()){
        user_command cmd = get_user_input();
        if(cmd.type == open_new_document){
            const std::string new_name=get_filename_from_user();
            std::thread t(edit_document,new_name);//启动新线程打开文档
            t.detach();//分离此线程
        }
        else{
            process_user_input(cmd);
        }
    }
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

