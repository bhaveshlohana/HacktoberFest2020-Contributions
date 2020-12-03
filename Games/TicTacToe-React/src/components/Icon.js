import React from 'react';
import {FaRegCircle, FaPen, FaTimes} from 'react-icons/fa';

const Icon = ({name}) => {
        switch (name) {
            case "circle":
                return <FaRegCircle className="icon" />
            case "cross":
                return <FaTimes className="icon"/>
            default:
                return <FaPen className="icon"/>
        }
}

export default Icon;