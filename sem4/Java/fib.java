 public static void fib(int a){
  int arr[] = new int[2*a];
  arr[0] = 0;
  arr[1] = 1;
  for (int i =  2; i < a ; i++){
    arr[i] = arr[i-1] + arr[i-2];
  }
  System.out.println(arr[a-1]);

}


class Main {
    public static int fibo(int a){
        if (a  < 2){
            return a;
        }
        return fibo(a-1) + fibo(a-2);
        
    }
    public static void main(String[] args) {
        int x = fibo(10);
        System.out.println(x);
    }
}
