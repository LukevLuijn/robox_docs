

> Log message syntax: ```@verbosityIndex[messageString;caller;file;lineNum;variables]*```

|Index|Variable|Description|Values|
|:---:|:---|:---|:---|
|00|**```@```**|Log message start char|```@```|
|01|**verbosityIndex**|Index of severity.|0..3 [ERROR,WARNING,INFO,DEBUG]|
|02|**messageString**|Actual message string.|String|
|03|**caller**|Caller of log message.|String|
|04|**file**|File name of caller.|String|
|05|**lineNum**|Line number of caller.|uint16_t|
|06|**variables**|Variable string, seperated by comma.|String|
|07|**```*```**|Log message stop char|```*```|

**!table** - *Log message protocol*
