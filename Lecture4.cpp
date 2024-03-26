#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>


namespace fs = std::filesystem;

bool chceckCorrectnessOfSudoku(std::vector<int> vec){
    if(vec.size()!=81){
        std::cout << "somthing wrong with sudoiku\n"<<std::endl;
        return false;
    }

    //rows
    auto iterator = vec.begin();
    int sum=0;
    while(iterator!=vec.end()){
        std::vector<int> row(iterator,iterator+9);

        for(int value:row){
            sum+=value;
        }
        if(sum!=45){return false;}
        iterator+=9;
    }
    //columns
    iterator = vec.begin();
    auto iterator2 = vec.begin();
    sum=0;
    while(iterator2!=vec.begin()+9){
        iterator=iterator2;
        while(iterator!=vec.end()){
            sum+=*iterator;
            std::advance(iterator, 9);
        }
        if(sum!=45){return false;}
        sum=0;
        iterator2++;
    }

    //boxes

}
bool isDigit(char a){
    if (a >= '0' && a <= '9') { return true; }else{
        return false;
    }

};
void processTxtFiles(const std::string& folderPath) {
    auto file = std::fstream("sudokuanswers.txt",std::ios::app);
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            // Open and process the text file
            std::ifstream file(entry.path());
            if (file.is_open()) {
                std::cout << "Contents of " << entry.path() << ":\n";
                std::string line;
                std::vector<int> vec;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                    for(char num:line){
                        if(isDigit(num)){
                            vec.push_back(int(num));
                        }
                    }

                }
                file.close();
                if(chceckCorrectnessOfSudoku(vec)){
                    auto file2 = std::ofstream("sudokuanswers.txt",std::ios::app);
                    std::string filename = entry.path().filename().string();
                    file2 << "Correct sudeoku in file: "<<filename<<"\n";
                    file2.close();
                }


            } else {
                std::cerr << "Unable to open file: " << entry.path() << std::endl;
            }
        }
    }
}

auto main() -> int{

    std::string folderpath = "C:/Users/Arek/Downloads/sudoku";
    processTxtFiles(folderpath);




    auto first = std::string("Hello there1");
    file << first;
    file.close();



    return 0;
}



