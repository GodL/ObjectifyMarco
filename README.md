# ObjectifyMarco
A series of macros defined for objective-c

Introduce

` OM_PASTEARG(...) 连接参数,最多支持9个参数 `

` OM_ClassForceify(obj,Class) 对象类型强制转换`</br>
    `example:`<br>
          ` UILabel* label = OM_ClassForceify(view,UILabel);`

` OM_BasicForceity(obj,type) 普通类型强制转换`

` OM_Init(block) 构造方法`

` classify(Class) Class` 

` initializeify(Class) 构造对象宏`</br>
    `example:`</br>
           `UILabel* label = @initializeify(UILabel);`

` modelify(Class,JSON) model化(必须导入YYModel)`
    
` modelsify(Class,JSON) model化(必须导入YYModel,返回一个数组)`

` scheduleify(OBJ,...) 执行一个方法`</br>
    `example:`</br>
            `设置一个label的text;`</br>
            `scheduleify(label,setText:,text) or scheduleify(label,setText:text)`

` recursionCallifyCallify(OBJ,...) 递归调用(最多支持9个参数)`</br>
    `example:`</br>
           `recursionCallifyCallify(UILabel,alloc,init,setText:text);(递归调用是将上一次调用的返回值调用下一个方法)`

` sequentialCallify(OBJ,...) 连续调用(最多支持9个参数)`</br>
    `example:`</br>
          ` UILabel* label = @initializeify(UILabel);`</br>
           `sequentialCallify(label,setTag:11,setText:@"",setFont:nil,setEnabled:YES);(连续调用是将传入的OBJ,依次执行后面传入的方法)`
