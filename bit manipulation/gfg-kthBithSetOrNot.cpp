bool checkKthBit(int n, int k) {
    // Your code here
    if(n & (1<<k)) return true;
    return false;
}