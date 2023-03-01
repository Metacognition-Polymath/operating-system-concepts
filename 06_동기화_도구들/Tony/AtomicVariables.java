import java.util.concurrent.atomic.AtomicBoolean;

public class AtomicVariables {
  static int count = 0;

  static int turn = 0;
  static AtomicBoolean[] flag;
  static {
    flag = new AtomicBoolean[2];
    for (int i = 0; i < flag.length; i++) {
      flag[i] = new AtomicBoolean(false);
    }
  }

  static class Producer implements Runnable {
    @Override
    public void run() {
      for (int i = 0; i < 10000; i++) {
        // entry section
        flag[0].set(true);
        turn = 1;
        // flag : Atomic variables
        while (flag[1].get() && turn == 1) {
        }

        // critical section
        count++;

        // exit section
        flag[0].set(false);

        // remainder section
      }
    }
  }

  static class Consumer implements Runnable {
    @Override
    public void run() {
      for (int i = 0; i < 10000; i++) {
        // entry section
        flag[1].set(true);
        turn = 0;
        while (flag[0].get() && turn == 0) {
        }

        // critical section
        count++;

        // exit section
        flag[1].set(false);

        // remainder section
      }
    }
  }

  public static void main(String[] args) {
    Thread t1 = new Thread(new Producer());
    Thread t2 = new Thread(new Consumer());

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
