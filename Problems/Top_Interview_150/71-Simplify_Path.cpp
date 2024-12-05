class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stackPath; // Stack to manage valid path components
        stringstream ss(path);
        string file;

        // Split the path by '/'
        while (getline(ss, file, '/')) {
            if (file == "..") {
                if (!stackPath.empty()) {
                    stackPath.pop(); // Go one directory up
                }
            } else if (file != "." && !file.empty()) {
                stackPath.push(file); // Add valid directory or file
            }
        }

        // Reconstruct the simplified path
        string newPath = "";
        while (!stackPath.empty()) {
            newPath = "/" + stackPath.top() + newPath; // Build path in reverse
            stackPath.pop();
        }

        return newPath.empty() ? "/" : newPath; // Return "/" if the stack is empty
    }
};
