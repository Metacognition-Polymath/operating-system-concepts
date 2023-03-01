class CountTest implements Runnable {
  static int count = 0;
  @Override
  public void run() {
    // 5000 부터 사이드 이펙트 발생
    for (int i = 0; i < 10000; i++) {
      count++;
    }
  }
}

public class RaceCondition {
  public static void main(String[] args) throws InterruptedException {
    Thread t1 = new Thread(new CountTest());
    Thread t2 = new Thread(new CountTest());
    t1.start();
    t2.start();
    t1.join();
    t2.join();
    System.out.println(CountTest.count);
  }
}