import QtQuick
import UICommon.Base

CImage{
    id: indicator
    source: UIConstants.radio_indicator_state_active_toggle_false_48x48
    property bool isSelected: false
    property bool inActiveState: false
    width: 48
    height: 48
    states:[
        State{
            when: ((!indicator.isSelected) && indicator.inActiveState)
            PropertyChanges{ target : indicator; source: UIConstants.radio_indicator_state_inactive_toggle_false_48x48}
        },
        State{
            when: (indicator.isSelected && indicator.inActiveState)
            PropertyChanges{ target : indicator; source: UIConstants.radio_indicator_state_inactive_toggle_true_48x48}
        },
        State{
            when: !indicator.isSelected
            PropertyChanges{ target : indicator; source: UIConstants.radio_indicator_state_active_toggle_false_48x48}
        },
        State{
            when: indicator.isSelected
            PropertyChanges{ target : indicator; source: UIConstants.radio_indicator_state_active_toggle_true_48x48}
        }
    ]
}
