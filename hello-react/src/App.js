import React from 'react';
import './App.css';
import Home from './components/Home'
import City from './components/City'
import { Route, Routes } from 'react-router-dom';

function App() {
  return (
    <>
      <Routes>
        <Route exact path="/" element={<Home/>}/>
        <Route path="/city/:cityName" element={<City/>}/>
      </Routes>
    </>
  );
}
export default App;