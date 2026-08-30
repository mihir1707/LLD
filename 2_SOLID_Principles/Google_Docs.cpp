#include<bits/stdc++.h>
using namespace std;


// Abstraction for document elements
class DocumentElement{
public:
    virtual string rander() = 0;
};

// for text elements
class TextElement : public DocumentElement{
private:
    string text;

public:
    TextElement(string text){
        this->text = text;
    }

    string rander() override {
        return text;
    }
};

// for image elements
class ImageElement : public DocumentElement{
private:
    string imagePath;

public:
    ImageElement(string path){
        imagePath=path;
    }

    string rander() override {
        return "[Image: "+ imagePath + "]";
    }
};

// line break in document
class NewLineElement : public DocumentElement{
public:
    string rander() override{
        return "\n";
    }
};

// for holding a collection of elements
class Document{
private:
    vector<DocumentElement*> documentElements;

public:
    void addElement(DocumentElement* element){
        documentElements.push_back(element);
    }
    
    string rander(){
        string result;
        for(auto& element: documentElements){
            result += element->rander();
        }
        return result;
    }
};

// Persistence abstraction
class Persistence{
public:
    virtual void save(string data) = 0;
};

// FileStorage implementation of Persistence
class FileStorage : public Persistence{
public:
    void save(string data) override {
        ofstream outFile("document.txt");
        if(outFile){
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else{
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

// Placeholder DBStorage implementation
class DBStorage : public Persistence{
public:
    void save(string data) override {
        cout << "Save to DB" << endl;
    }
};

// DocumentEditor class managing client interactions
class DocumentEditor{
private:
    Document *document;
    Persistence *storage;
    string renderedDocument;

public:
    DocumentEditor(Document *document, Persistence *storage){
        this->document = document;
        this->storage = storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document -> rander();
        }
        return renderedDocument;
    }

    void saveDocument(){
        storage -> save(renderDocument());
    }
};


int main(){

    Document* document = new Document();
    Persistence* persistence = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document, persistence);

    editor->addText("Welcome!");
    editor->addNewLine();
    editor->addText("This is a document editor.");
    editor->addNewLine();
    editor->addText("Text after new line");
    editor->addNewLine();
    editor->addImage("image.jpg");

    cout << editor->renderDocument() << endl;

    editor -> saveDocument();

    return 0;
}