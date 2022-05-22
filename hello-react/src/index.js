import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import {BrowserRouter} from 'react-router-dom';

/*React.createElement = 'h1', 'null', 'root'; */
ReactDOM.render(
  <BrowserRouter>
        <App />
    </BrowserRouter>,
  document.getElementById('root')
);


/*An exmaple of PURE JS to create an element */
// var h1 = document.createElement('h1');
// h1.innerHTML = "Saudya";
// document.getElementById('root').appendChild(h1);
