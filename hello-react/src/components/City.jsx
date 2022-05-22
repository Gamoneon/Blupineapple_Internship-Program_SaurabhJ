import React from 'react';
import '../components/css/city.css'
import cityDetails from '../city.json';
import styled from 'styled-components';
import { Link, useParams } from "react-router-dom";

const Button = styled.button`
background-color: #8c9eff;
color: white;
padding: 5px 15px;
margin: 5px 5px;
outline:0;
box-shadow: 0px 2px 2px lightgray;
cursor: pointer;
transition: ease background-color 250ms;
&:hover{
    background-color:#536dfe;
}
`;

const City = () => {
    const {cityName}= useParams();
    return (
        <>
            <Link to='/'>
                <Button>Back</Button></Link>
            <div className='cityList'>
                {cityDetails.map(city => {
                    if(city.Name===cityName)
                    return (
                        <div key={city.id}>
                            <h3>{city.Name}</h3>
                            <p>{city.Name} is also known as {city['Nick-name']}!</p>
                            <img className="cityImg" src={city.src} alt={city.Name}></img>
                        </div>
                    )
                })
                }
            </div>
        </>
    )
};

export default City;