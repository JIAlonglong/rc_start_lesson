    //初始化ROS节点
    // ros::init(argc,argv,"erGouZi",ros::init_options::AnonymousName);//避免节点重复启动，为节点名称加一个随机数后缀
    //argc:传入参数个数
    //argv[]:传入参数数值
    //节点名称
    //节点启动项：为节点名称后缀一个随机数

    
    
    
    
    
    
    
    //创建发布者对象；
    /* 
        作用：创建发布者对象

        模板：被发布的消息的类型

        参数：
            1.话题名称
            2.队列长度
            3.latch(可选)   如果设置为true,会保存发布方最后一条消息，并且新的订阅对象连接到发布方时，发布方会将这条消息发送给订阅者           
        使用:
            latch设置为true的作用
            以静态地图发布为例，方案一：可以使用固定频率发布地图数据，但是效率低；方案二可以将地图发布对象的latch设置为true，并且发布方只发送一次数据，每当订阅者连接时，就可以将地图数据发送给订阅者（只发送一次），这样就提高了数据的发送效率
    */
    // ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10,true);
