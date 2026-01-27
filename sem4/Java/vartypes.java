class example{
 static int a = 2;
 int c;	
 public example(int c){
  c =c ;
}

}
public class vartypes{
	public static void main(String[] args){
		example e = new example(6);
		int c = 2;
      		System.out.println("static variable " + example.a);		
		System.out.println("Local variable " + c);
		System.out.println("Instance variable " + e.c);


}

}
