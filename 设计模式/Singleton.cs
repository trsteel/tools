/*
 * 单例模式实现，考虑多线程，只能生成一个实例
 */

 //加锁前后两次判断实例是否存在，常规解法，效率低
public sealed class Singleton3{
  private Singleton3(){}
  private static Object syncObj = new Object();

  private static Singleton3 instance = null;
  public static Singleton3 Instance{
    get{
      if(instance==null){
        lock(syncObj){
          if(instance==null)
            instance=new Singleton3();
        }
      }
    }
    return instance;
  }
}

//利用静态构造函数,确保只调用一次，实例创建时间不好把握
public sealed class Singleton4{
  private Singleton4(){}

  private static Singleton4 instance = new Singleton4;
  public static Singleton4 Instance{
    get{
      return instance;
    }
  }
}

//按需创建实例
public sealed class Singleton5{
  Singleton5(){}

  public static Singleton5 Instance{
    get{
      return Nested.instance;
    }
  }

  class Nested{
    static Nested(){}
    
    internal static readonly Singleton5 instance = new Singleton5();
  }
}
