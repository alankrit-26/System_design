#include<bits/stdc++.h>
using namespace std;


class GoogleDocs{
    private:
    vector<string>text;    
    vector<string>path;
    public:
     
    void addText(string sx){
        text.push_back(sx);
    }

    void addPath(string s1){
        path.push_back(s1);
    }

    void render(){
        for(auto it:text){
            cout<<"Text: "<<it<<endl;
        }
    }

    void renderFile(){
        ifstream infile;
        string line;
        infile.open("/Users/alankritsinghkaim/Desktop/PLACEEMENTS/SystemDesignCode/document.txt");
        if(infile.is_open()){
            cout<<"File rendering"<<endl;
            while(getline(infile,line)){
                cout<<line<<" ";
            }
            infile.close();
        }
        else{
            cout<<"Error opening the file";
        }
    }
};
int main(){
    GoogleDocs* pt=new GoogleDocs();
    pt->renderFile();
}