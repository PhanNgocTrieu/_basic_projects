import QtQuick
QtObject{
    id: animationObject
    /**
      *  @brief Duration of the animation
      */
    property int duration: 300
    /**
      * @brief The default state
      */
    property string state1
    /**
      * @brief The activated state
      */
    property string state2
    /**
      * @brief The Set of properties in The default State
      */
    property list<PropertyChanges> preState
    /**
      * @brief The Set of properties in The Activated State
      */
    property list<PropertyChanges> afterState
    /**
      * @brief Register the property which will be modified during the state changes
      */
    property string registerProperties
    /**
      * @brief Signal to handle in case of finishing switching to The State2
      */
    signal finishState2()
    /**
      * @brief Signal to handle in case of finishing switching to The State1
      */
    signal finishState1()
    /**
      * @brief Transition to all States
      */
    property list<Transition> transitions:[
        Transition{
            to: state1
            SequentialAnimation{
                 NumberAnimation{ duration: animationObject.duration; properties: registerProperties }
                 ScriptAction{script: finishState1()}
            }
        },
        Transition{
            to: state2
            SequentialAnimation{
                NumberAnimation{ duration: animationObject.duration; properties: registerProperties }
                ScriptAction{script: finishState2()}
            }

        }
    ]
    /**
      * @brief Define the properties of each State
      */
    property list<State> states:[
        State{
            name: state1
            changes: preState
        },
        State{
            name: state2
            changes: afterState
        }
    ]
}