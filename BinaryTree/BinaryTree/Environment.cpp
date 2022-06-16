#include "Environment.h"
#include "Timer.h"


std::vector<Object*> Environment::objects = std::vector<Object*>();
int Environment::lifetimeObjectCount = 0;


Environment::Environment()
{

}

Environment::~Environment()
{
}

void Environment::Start()
{
    InitWindow(1200, 800, "Double Linked List");

    Timer timer = Timer();
    float DeltaTime = 0;

    

    new UIPanel(0, GetScreenHeight() - 350, GetScreenWidth(), 350, ColorToInt(BLACK));

    new UIText(0, GetScreenHeight() - 350, "*Due to visualisation limitations, only 5 layers of the tree can be displayed.", 25, 0xFFFFFFFF);

    addNumInput = new UIInputBox(GetScreenWidth() - 100, GetScreenHeight() - 100, 100, 50, 0x666666FF, 0xAAFFFFFF, 0x00FFFFFF, new UIText(0, 0, "0", 16, 0x000000FF), 3, true);
    addNumInput->intMax = 999;
    addNumInput->intMin = 0;
    new UIText(GetScreenWidth() - 150, GetScreenHeight() - 145, "Value:", 16, 0xFFFFFFFF);

    UIButton* addBackButton = new UIButton(GetScreenWidth() - 300, GetScreenHeight() - 100, 200, 50, 0x888888FF, 0x00FF00FF, new UIText(0, 0, "Add value", 16, 0xFFFFFFFF));
    addBackButton->AssignCallMethod(std::bind(&Environment::AddListElement, this)); 
    
    UIButton* removeBackButton = new UIButton(GetScreenWidth() - 550, GetScreenHeight() - 100, 200, 50, 0x888888FF, 0xFF0000FF, new UIText(0, 0, "Remove value", 16, 0xFFFFFFFF));
    removeBackButton->AssignCallMethod(std::bind(&Environment::RemoveListElement, this)); 
    
    
    UIButton* randomise = new UIButton(GetScreenWidth() - 800, GetScreenHeight() - 100, 200, 50, 0x888888FF, 0xFF0000FF, new UIText(0, 0, "Randomise Tree", 16, 0xFFFFFFFF));
    randomise->AssignCallMethod(std::bind(&Environment::RandomiseBinaryTree, this));



    while (!WindowShouldClose()) {
        DeltaTime = timer.RecordNewTime();

        Update(DeltaTime);

        Draw(DeltaTime);

    }


    ResetGameObjects();

    CloseWindow();

}
void Environment::ResetGameObjects() {

    std::vector<std::function<void()>> storeDestroy;
    // Store all objects for deletion
    for (int i = 0; i < objects.size(); i++) {
        storeDestroy.push_back(std::bind(&Object::DeleteSelf, objects[i]));
    }
    // Destroy all objects
    for (int del = 0; del < storeDestroy.size(); del++) {
        storeDestroy[del]();
    }
    storeDestroy.clear();
    storeDestroy.shrink_to_fit();
    objects.shrink_to_fit();
}



void Environment::Update(float DeltaTime)
{
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->Update(DeltaTime);
    }

    
    
    
}



void Environment::DisplayBinaryTreeNode(TreeNode<int>* node, int x, int y, int iteration)
{
    if (iteration == 5) {
        return;
    }

    if (node == nullptr) {
        return;
    }

    
    Vector2 dist = { 250*powf(0.5, iteration), 75};
    float r = 25;

    Vector2 normDist = Vector2Normalize(dist);


    // Recurse through the left node
    if (node->left != nullptr) {
        DisplayBinaryTreeNode(node->left, x - dist.x, y + dist.y, iteration+1);
        DrawLineEx({ (float)x, (float)y }, { x - dist.x + (normDist.x * r), y + dist.y - (normDist.y * r) }, 10, RED);
    }
    
    // Recurse through the right node
    if (node->right != nullptr) {
        DisplayBinaryTreeNode(node->right, x + dist.x, y + dist.y, iteration + 1);
        DrawLineEx({ (float)x, (float)y }, { x + dist.x - (normDist.x * r), y + dist.y - (normDist.y * r) }, 10, RED);
    }

    // Draw the node value
    DrawCircle(x, y, r, BLACK);
    std::string valText = std::to_string(node->value);
    DrawText(valText.c_str(), x-(MeasureText(valText.c_str(), 16)/2), y - 5, 16, WHITE);
}



void Environment::Draw(float DeltaTime)
{
    BeginDrawing();

    ClearBackground(WHITE);

    for (int i = 0; i < objects.size(); i++) {
        objects[i]->Draw();
    }

    DisplayBinaryTreeNode(binaryTree.GetFirstNode(), GetScreenWidth() / 2, 100);

    EndDrawing();
}


void Environment::AddListElement()
{
    binaryTree.Add(std::stoi(addNumInput->currentText));
}

void Environment::RemoveListElement()
{
    binaryTree.Remove(std::stoi(addNumInput->currentText));
}

void Environment::RandomiseBinaryTree()
{
    binaryTree.Clear();
    int amount = rand() % 30 + 2;

    for (int i = 0; i < amount; i++) {
        binaryTree.Add(rand() % 999 + 0);
    }

}


