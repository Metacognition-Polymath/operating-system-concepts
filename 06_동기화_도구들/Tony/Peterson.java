public class Peterson {
  static int count = 0;
  static int turn = 0;
  static boolean[] flag = new boolean[2];
  
  public static void main(String[] args) {
    Thread t1 = new Thread(new Runnable() {
      public void run() {
        for (int i = 0; i < 1000; i++) {
          // entry section
          flag[0] = true;
          turn = 1;

          while (flag[1] && turn == 1) {
            // busy wait
          }

          // critical section
          count++;

          // exit section
          flag[0] = false;

          // remainder section
        }
      }
    });
    
    Thread t2 = new Thread(new Runnable() {
      public void run() {
        for (int i = 0; i < 1000; i++) {
          // entry section
          flag[1] = true;
          turn = 0;
          while (flag[0] && turn == 0) {
            // busy wait
          }

          // critical section
          count++;

          // exit section
          flag[1] = false;

          // remainder section
        }
      }
    });
    
    t1.start();
    t2.start();
    
    try {
      t1.join();
      t2.join();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    
    System.out.println(count);
  }
}
