import React from "react";
import '../components/css/home.css';
import cityDetails from '../city.json';
import { Link } from "react-router-dom";

function Home() {
    return (
        <div className="HomePage">
            <h1>TravellerCity.com</h1>
            <p>
                Welcome to TravellerCity.com, choose a city to Travel
            </p>
            <div className='cityList'>
                <ol>
                    {cityDetails.map(city => {
                        return (
                            <li key={city.id}>
                                <h3><Link to={'/city/' + city.Name}>{city.Name}</Link></h3>
                            </li>
                        )
                    })
                    }
                </ol>
            </div>
        </div>
    );
}

export default Home;