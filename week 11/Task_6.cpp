#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

struct ExprNode {
    string data;
    ExprNode* left;
    ExprNode* right;
    ExprNode(string val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

ExprNode* buildFromPostfix(const string& postfix) {
    stack<ExprNode*> s;
    istringstream iss(postfix);
    string token;
    while (iss >> token) {
        ExprNode* node = new ExprNode(token);
        if (isOperator(token)) {
            node->right = s.top(); s.pop();
            node->left  = s.top(); s.pop();
        }
        s.push(node);
    }
    return s.top();
}

void printInfix(ExprNode* root) {
    if (!root) return;
    if (root->left && root->right) cout << "(";
    printInfix(root->left);
    cout << root->data;
    printInfix(root->right);
    if (root->left && root->right) cout << ")";
}

void printPrefix(ExprNode* root) {
    if (!root) return;
    cout << root->data << " ";
    printPrefix(root->left);
    printPrefix(root->right);
}

void printPostfix(ExprNode* root) {
    if (!root) return;
    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->data << " ";
}

int evaluate(ExprNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return stoi(root->data);
    int l = evaluate(root->left), r = evaluate(root->right);
    if (root->data == "+") return l + r;
    if (root->data == "-") return l - r;
    if (root->data == "*") return l * r;
    if (root->data == "/") return l / r;
    return 0;
}

int main() {
    string postfix = "3 5 + 8 2 - *";
    ExprNode* root = buildFromPostfix(postfix);

    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl;

    cout << "Final Answer: " << evaluate(root) << endl;

    return 0;
}
