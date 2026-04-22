<?php
declare(strict_types=1);

namespace App\Controller;

/**
 * Tételek Controller
 *
 * @property \App\Model\Table\TételekTable $Tételek
 *
 * @method \App\Model\Entity\Tételek[]|\Cake\Datasource\ResultSetInterface paginate($object = null, array $settings = [])
 */
class TételekController extends AppController
{
    /**
     * Index method
     *
     * @return \Cake\Http\Response|null
     */
    public function index()
    {
        $tételek = $this->paginate($this->Tételek);

        $this->set(compact('tételek'));
    }

    /**
     * View method
     *
     * @param string|null $id Tételek id.
     * @return \Cake\Http\Response|null
     * @throws \Cake\Datasource\Exception\RecordNotFoundException When record not found.
     */
    public function view($id = null)
    {
        $tételek = $this->Tételek->get($id, [
            'contain' => [],
        ]);

        $this->set('tételek', $tételek);
    }

    /**
     * Add method
     *
     * @return \Cake\Http\Response|null Redirects on successful add, renders view otherwise.
     */
    public function add()
    {
        $tételek = $this->Tételek->newEmptyEntity();
        if ($this->request->is('post')) {
            $tételek = $this->Tételek->patchEntity($tételek, $this->request->getData());
            if ($this->Tételek->save($tételek)) {
                $this->Flash->success(__('The tételek has been saved.'));

                return $this->redirect(['action' => 'index']);
            }
            $this->Flash->error(__('The tételek could not be saved. Please, try again.'));
        }
        $this->set(compact('tételek'));
    }

    /**
     * Edit method
     *
     * @param string|null $id Tételek id.
     * @return \Cake\Http\Response|null Redirects on successful edit, renders view otherwise.
     * @throws \Cake\Datasource\Exception\RecordNotFoundException When record not found.
     */
    public function edit($id = null)
    {
        $tételek = $this->Tételek->get($id, [
            'contain' => [],
        ]);
        if ($this->request->is(['patch', 'post', 'put'])) {
            $tételek = $this->Tételek->patchEntity($tételek, $this->request->getData());
            if ($this->Tételek->save($tételek)) {
                $this->Flash->success(__('The tételek has been saved.'));

                return $this->redirect(['action' => 'index']);
            }
            $this->Flash->error(__('The tételek could not be saved. Please, try again.'));
        }
        $this->set(compact('tételek'));
    }

    /**
     * Delete method
     *
     * @param string|null $id Tételek id.
     * @return \Cake\Http\Response|null Redirects to index.
     * @throws \Cake\Datasource\Exception\RecordNotFoundException When record not found.
     */
    public function delete($id = null)
    {
        $this->request->allowMethod(['post', 'delete']);
        $tételek = $this->Tételek->get($id);
        if ($this->Tételek->delete($tételek)) {
            $this->Flash->success(__('The tételek has been deleted.'));
        } else {
            $this->Flash->error(__('The tételek could not be deleted. Please, try again.'));
        }

        return $this->redirect(['action' => 'index']);
    }
	
	public function megnyertTételekListázása($azon = null)
	{
		$ajánlattevőazonosító = $this->request->getParam('pass');
		$tételek = $this->Tételek->find('nyertesajánlattevő', ['nyertesajánlattevő' => $ajánlattevőazonosító]);
		$this->set(['tételek' => $tételek, 'nyertesajánlattevő' => $ajánlattevőazonosító]);
	}
}
