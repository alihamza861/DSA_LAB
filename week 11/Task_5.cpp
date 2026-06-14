#include <iostream>
#include <string>
using namespace std;

struct ExprNode {
    string data;
    ExprNode* left;
    ExprNode* right;
    ExprNode(string val) : data(val), left(nullptr), right(nullptr) {}
};

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
    if (!root->left && !root->right)
        return stoi(root->data);

    int left  = evaluate(root->left);
    int right = evaluate(root->right);

    if (root->data == "+") { cout << left << " + " << right << " = " << left + right << endl; return left + right; }
    if (root->data == "-") { cout << left << " - " << right << " = " << left - right << endl; return left - right; }
    if (root->data == "*") { cout << left << " * " << right << " = " << left * right << endl; return left * right; }
    if (root->data == "/") { cout << left << " / " << right << " = " << left / right << endl; return left / right; }
    return 0;
}

int main() {
    ExprNode* root = new ExprNode("*");
    ExprNode* plus = new ExprNode("+");
    ExprNode* minus = new ExprNode("-");
    ExprNode* n3 = new ExprNode("3");
    ExprNode* n5 = new ExprNode("5");
    ExprNode* n8 = new ExprNode("8");
    ExprNode* n2 = new ExprNode("2");

    root->left  = plus;   root->right = minus;
    plus->left  = n3;     plus->right = n5;
    minus->left = n8;     minus->right = n2;

    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl;

    cout << "Evaluation:" << endl;
    int result = evaluate(root);
    cout << "Final Answer: " << result << endl;

    return 0;
}
