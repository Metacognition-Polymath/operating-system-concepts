class CashBox {
  private int[] buffer;
  private int count, in, out;
  public CashBox(int bufferSize) {
    buffer = new int[bufferSize];
    count = 0;
    in = 0;
    out = 0;
  }

  /**
   * Producer가 give를 호출
   */
  synchronized public void give(int money) throws InterruptedException {
    while (count == buffer.length) {
      try {
        wait();
      } catch (Exception e) {
      }
    }
    buffer[in] = money;
    in = (in + 1) % buffer.length;
    count++;
    System.out.printf("여기 있다, 용돈: %d원\n", money);
    notify();
  }

  /**
   * Consumer가 take를 호출
   */
  synchronized public int take() throws InterruptedException {
    while (count == 0) {
      try {
        wait();
      } catch (Exception e) {
      }
    }
    int money = buffer[out];
    out = (out + 1) % buffer.length;
    count--;
    System.out.printf("고마워요, 용돈: %d원\n", money);
    notify();
    return money;
  }
}

class ProdRunner implements Runnable {
  private CashBox cashBox;

  public ProdRunner(CashBox cashBox) {
    this.cashBox = cashBox;
  }

  @Override
  public void run() {
    try {
      while (true) {
        Thread.sleep((long)Math.random() * 500);
        int money = ((int)(1 + Math.random() * 9)) * 10000;
        cashBox.give(money);
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}

class ConsRunner implements Runnable {
  private CashBox cashBox;

  public ConsRunner(CashBox cashBox) {
    this.cashBox = cashBox;
  }

  @Override
  public void run() {
    try {
      while (true) {
        Thread.sleep((long)Math.random() * 500);
        int money = cashBox.take();
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}

public class BoundedBuffer {
  public static void main(String[] args) {
    CashBox cashBox = new CashBox(5); // Producer와 Consumer가 공유하는 객체
    Thread[] producers = new Thread[5];
    Thread[] consumers = new Thread[5];

    // Create threads of producers
    for (int i = 0; i < producers.length; i++) {
      producers[i] = new Thread(new ProdRunner(cashBox));
      producers[i].start();
    }

    // Create threads of consumers
    for (int i = 0; i < consumers.length; i++) {
      consumers[i] = new Thread(new ConsRunner(cashBox));
      consumers[i].start();
    }
  } 
}
