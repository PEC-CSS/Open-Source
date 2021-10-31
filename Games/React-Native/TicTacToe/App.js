import React,{useState} from 'react'
import {
  View,
  StyleSheet,
  TouchableOpacity,
} from 'react-native'

import {
  Text,
  Container,
  Content,
  Card,
  Header,
  Body,
  H1,H3,
  Button,
  Title,
  NativeBaseProvider,
} from 'native-base'
import Icons from "./components/Icons"
import Snackbar from 'react-native-snackbar'

const itemArray= new Array(9).fill('empty')


const App = () => {
  const isWin=false;
  const [isCross,setIsCross]=useState(false)
  const [winMessage,setWinMessage]=useState('')
  
  const changeItem=(itemNumber)=>{
    if(winMessage){
      return Snackbar.show({
        text : winMessage,
        backgroundColor:"#000",
        textColor:"#FFF"
      })
    }
    if(itemArray[itemNumber]==='empty'){
      itemArray[itemNumber]= isCross ? ('cross'):('circle')
      setIsCross(!isCross)
    }else{
      Snackbar.show({
        text:"The Position is already filled",
        backgroundColor:"#FF6263",
        textColor:"#FFF"
      })
    }
    
    checkIsWinner()

  }
  const reloadGame=()=>{
    setIsCross(false)
    setWinMessage('')
    itemArray.fill('empty',0,9)

  }
  const checkIsWinner=()=>{
    if(
      itemArray[0]===itemArray[1]&&
      itemArray[1]===itemArray[2]&&
      itemArray[0]!=='empty'
    ){
      setWinMessage(`${itemArray[0]} won`)
    }
    
    if(
      itemArray[3]===itemArray[4]&&
      itemArray[4]===itemArray[5]&&
      itemArray[3]!=='empty'
    ){
      setWinMessage(`${itemArray[3]} won`)
    }

    if(
      itemArray[6]===itemArray[7]&&
      itemArray[7]===itemArray[8]&&
      itemArray[6]!=='empty'
    ){
      setWinMessage(`${itemArray[6]} won`)
    }

    if(
      itemArray[0]===itemArray[4]&&
      itemArray[4]===itemArray[8]&&
      itemArray[0]!=='empty'
    ){
      setWinMessage(`${itemArray[0]} won`)
    }
    if(
      itemArray[2]===itemArray[4]&&
      itemArray[4]===itemArray[6]&&
      itemArray[2]!=='empty'
    ){
      setWinMessage(`${itemArray[2]} won`)
    }
    if(
      itemArray[0]===itemArray[3]&&
      itemArray[3]===itemArray[6]&&
      itemArray[0]!=='empty'
    ){
      setWinMessage(`${itemArray[0]} won`)
    }
    if(
      itemArray[1]===itemArray[4]&&
      itemArray[4]===itemArray[7]&&
      itemArray[1]!=='empty'
    ){
      setWinMessage(`${itemArray[1]} won`)
    }
    if(
      itemArray[2]===itemArray[5]&&
      itemArray[5]===itemArray[8]&&
      itemArray[2]!=='empty'
    ){
      setWinMessage(`${itemArray[2]} won`)
    }
    if(
      isWin===false &&itemArray[0]!=='empty'&&itemArray[1]!=='empty'&&itemArray[2]!=='empty'&&itemArray[3]!=='empty'&&itemArray[4]!=='empty'&&itemArray[5]!=='empty'&&itemArray[6]!=='empty'&&itemArray[7]!=='empty'&&itemArray[8]!=='empty'
    ){
      setWinMessage('Draw')
    }

  }


  return (
    <Container  style={{backgroundColor: "333945", padding: 5}}>
      <Header>
        <Body>
          <Title>
            Tic-Tac-Toe
          </Title>
        </Body>
      </Header>
      <Content>
        <View style={styles.gride}>
          {
            itemArray.map((item,index)=>(
              <TouchableOpacity
              style={styles.box}
              key={index}
              onPress={()=>changeItem(index)}
              >
                <Card style={styles.card}>
                  <Icons name={item} />
                </Card>
              </TouchableOpacity>
            ))
          }
        </View>
        {winMessage?(
          <View>
            <H1 style={styles.message}>{winMessage}</H1>
            <Button
            onPress={reloadGame}
            primary
            block
            rounded
            >
              <Text>Reload Game</Text>
           </Button>
          </View>
        ):(
          <H3 style={styles.message} >
            {isCross?('Cross'):('Circle')} turns
          </H3>
        )}
      </Content>
    </Container>
  )
}


export default App

const styles = StyleSheet.create(
  {
    gride:{
      flex:1,
      flexDirection:"row",
      flexWrap:"wrap",
      marginTop:50
    },
    card :{
      height:120,
      justifyContent:"center",
      alignItems:"center"
    },
    box:{
      width:"33%" ,
      marginBottom:3,
    },
    message:{
      textAlign:"center",
      textTransform:"uppercase",
      color:"#FFF",
      marginTop:20,
      backgroundColor:"#4652B3",
      paddingVertical: 10,
      marginVertical:30,
    },
  }
)